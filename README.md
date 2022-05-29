# dictionary
suomi-englanti-suomi sanakirjaohjelma / finnish-english-finnish dictionary program.

Ohjelmassa käyttäjä syöttää sanan suomeksi tai englanniksi. Ohjelma tulostaa sanan vastineen toisella kielellä muodossa:
"Sana sana1 englanniksi on word1" <--> "Sana koira englanniksi on dog" tai "Sana word2 suomeksi on sana2" <--> "Sana cat suomeksi on kissa"

Mikäli sanaa ei löydy sanakirjasta, tulostetaan virheilmoitus: "Sanaa haettavasana ei loytynyt sanakirjasta"
Sanat sijaitsevat tiedostossa 'sanakirja.txt', jossa ne ovat erotettu toisistaan puolipisteellä: "sana1suomeksi;sana1englanniksi"

------------------------------------------------------------------------------------------------------------------------

The program asks a user to enter a word in Finnish or English.
The corresponding word will be printed in another language like in example above.

If the word is not included in the dictionary, an error message will be printed: "Sanaa haettavasana ei loytynyt sanakirjasta"
The words are stored in the textfile 'sanakirja.txt' which conforms the following structure:

"finnishWord1;englishWord1"
"finnishWord2;englishWord2"
etc..
