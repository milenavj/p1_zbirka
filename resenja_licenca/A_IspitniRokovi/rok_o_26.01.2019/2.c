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

#define MAKS_DUZINA 101

int main() {
  /* Deklaracija potrebnih promenljivih. */
  char email[MAKS_DUZINA];
  char sifrovani_email[MAKS_DUZINA];
  char *at_pozicija;

  /* Ucitavanje elektronske adrese. */
  scanf("%s", email);

  /* Odredjivanje pozicije @ karaktera. */
  at_pozicija = strchr(email, '@');

  /* Ukoliko elektronska adresa ne sadrzi @ karakter, ispisuje se
     trazena poruka. */
  if (at_pozicija == NULL) {
    fprintf(stderr, "-1\n");
    exit(EXIT_FAILURE);
  }

  /* Sifrovana adresa inicijalno sadrzi samo terminirajucu nulu. */
  sifrovani_email[0] = '\0';

  /* U sifrovanu adresu se kopira deo originalne adrese koji
     prethodi @ karakteru. */
  *at_pozicija = '\0';
  strcpy(sifrovani_email, email);

  /* Zatim se sifrovana adresa nadovezuje sa [AT] zamenom. */
  strcat(sifrovani_email, "[AT]");

  /* Na kraju se sifrovana adresa nadovezuje sa delom originalne
     adrese koji se nalazi posle @ karaktera. */
  strcat(sifrovani_email, at_pozicija + 1);

  /* Ispis rezultata. */
  printf("%s\n", sifrovani_email);

  exit(EXIT_SUCCESS);
}
