/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 31
#define MAKS_REZULTAT 91

/* Niske se ne kopiraju naredbom dodele. Ukoliko je potrebno da
   neka niska ima isti sadrzaj kao i neka druga niska, moze se
   koristiti funkcija strcpy(t, s) koja kopira karaktere niske s u
   nisku t zajedno za terminirajucom nulom. Deklaracija ove
   funkcije se nalazi u zaglavlju string.h.

   Funkcija strcpy_klon predstavlja jednu implementaciju funkcije
   strcpy. */
void strcpy_klon(char kopija[], char original[]) {
  int i;
  for (i = 0; original[i]; i++)
    kopija[i] = original[i];

  kopija[i] = '\0';
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA], t[MAKS_REZULTAT];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Niska s se kopira u nisku t. */
  strcpy_klon(t, s);

  /* Funkcija strcat(s,t) nadovezuje karaktere niske s na kraj
     niske t i novu nisku terminira karakterom '\0'. Deklaracija
     ove funkcije se nalazi u zaglavlju string.h. */

  /* Niska s se jos dva puta nadovezuje na nisku t. */
  strcat(t, s);
  strcat(t, s);

  /* Ispis rezultata. */
  printf("Rezultujuca niska: %s\n", t);

  exit(EXIT_SUCCESS);
}
