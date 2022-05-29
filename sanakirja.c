#include <stdio.h>
#include <string.h>
#define maxPituus 100

void lueMerkkijono(char merkkijono[], int pituus);
void tyhjennaPuskuri(void);

int main(void) {

    FILE * sanakirja;

    int findFlag = 0; /* Ehtomuuttuja sanan löytymiseen sanakirjasta */

    char sana[maxPituus]; /* käyttäjän syöttämä sana */
    char rivi[maxPituus]; /* sanakirjan sisältö riveittäin */
    char erotinmerkkijono[] = ";";

    char * suomeksi; /* sana suomeksi */
    char * englanniksi; /* sana englanniksi */

    // Avataan sanakirja lukemista varten
    sanakirja = fopen("sanakirja.txt", "r");

    // Jos sanakirjan avaaminen jostakin syystä epäonnistuu, palauttaa fopen arvon NULL.
    if (sanakirja == NULL) {
        printf("Tiedoston avaaminen epäonnistui\n");
        return(0);
    }
    else {
        printf("Anna sana suomeksi tai englanniksi > ");
        lueMerkkijono(sana, maxPituus);

        // Käydään sanakirja läpi riveittäin
        while (fgets(rivi, maxPituus, sanakirja)) {

            // strtok "muistaa" merkkijonon, NULL kertoo että jatka entisen merkkijonon käsittelyä
            suomeksi = strtok(rivi, erotinmerkkijono);
            if (suomeksi[strlen(suomeksi) - 1] == '\n')
                suomeksi[strlen(suomeksi) - 1] = '\0';

            englanniksi = strtok(NULL, erotinmerkkijono);
            if (englanniksi[strlen(englanniksi) - 1] == '\n')
                englanniksi[strlen(englanniksi) - 1] = '\0';

            if (strcmp(sana, suomeksi) == 0) { // Jos riviltä löytyy käyttäjän suomeksi syöttämä sana
                printf("Sana %s englanniksi on %s", sana, englanniksi);
                findFlag = 1; // Käyttäjän sana löytyi sanakirjasta
                break;
            }
            if (strcmp(sana, englanniksi) == 0) { // Jos riviltä löytyy käyttäjän englanniksi syöttämä sana
                printf("Sana %s suomeksi on %s", sana, suomeksi);
                findFlag = 1; // Käyttäjän sana löytyi sanakirjasta
                break;
            }
        } /* while */

        // Suljetaan tiedosto käsittelyn lopuksi.
        fclose(sanakirja);

        if (findFlag == 0) // Jos sanaa ei löytynyt sanakirjasta
            printf("Sanaa %s ei loytynyt sanakirjasta\n", sana); // Tulostetaan virheilmoitus

    } /* else */

    return(0);

} /* main */


/* Lukee merkkijonon.
 * Jos merkkijonon lopussa, ennen lopetusmerkkiä on ylimääräinen rivinvaihto,
 * se korvataan lopetusmerkillä '\0' */
void lueMerkkijono(char merkkijono[], int pituus) {

    fgets(merkkijono, pituus, stdin);

    if (merkkijono[strlen(merkkijono) - 1] == '\n') {
        merkkijono[strlen(merkkijono) - 1] = '\0';
    }
    else {
        tyhjennaPuskuri();
    }
}

// Tyhjentää näppäimistöpuskurin
void tyhjennaPuskuri(void) {
    while(fgetc(stdin) != '\n');
}