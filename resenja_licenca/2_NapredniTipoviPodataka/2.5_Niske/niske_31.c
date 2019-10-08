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
#include <ctype.h>

#define MAKS_NISKA 20

/* Pomocna funkcija koja racuna dekadnu vrednost prosledjenog
   karaktera (npr. '1' ima vrednost 1, 'C' ima vrednost 12). */
unsigned vrednost_cifre(char c) {
  c = toupper(c);
  if (isdigit(c))
    return c - '0';
  else
    return c - 'A' + 10;
}

/* Funkcija racuna dekadnu vrednost neoznacenog broja zapisanog u
   datoj osnovi. */
unsigned int u_dekadni_sistem(char broj[], unsigned int osnova) {
  int i, n = strlen(broj);
  int rezultat = 0, tezina_pozicije = 1;

  for (i = n - 1; i >= 0; i--) {
    rezultat += vrednost_cifre(broj[i]) * tezina_pozicije;
    tezina_pozicije *= osnova;
  }

  return rezultat;
}

/* Funkcija obrce nisku s. */
void obrni(char s[]) {
  int i, j;
  int n = strlen(s);
  char c;

  for (i = 0, j = n - 1; i < j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

/* Pomocna funkcija koja dekadnu vrednost cifre pretvara u
   odgovarajuci karakter (npr. 12 u 'C', 5 u '5'). */
char ostatak_u_char(int ostatak) {
  if (ostatak < 10)
    return '0' + ostatak;
  else
    return 'A' + ostatak - 10;
}

/* Funkcija datu dekadnu vrednost broja prebacuje u broj u datoj
   osnovi. */
void iz_dekadnog_sistema(unsigned int broj, unsigned int osnova,
                         char rezultat[]) {
  int i = 0;
  int ostatak;

  do {
    ostatak = broj % osnova;
    broj = broj / osnova;
    rezultat[i] = ostatak_u_char(ostatak);
    i++;
  } while (broj);

  rezultat[i] = '\0';
  obrni(rezultat);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char broj[MAKS_NISKA], broj2[MAKS_NISKA];
  unsigned int osnova1, osnova2;

  /* Ucitavanje ulaznih podataka. */
  printf("Unesite n, o1 i o2: ");
  scanf("%s%u%u", broj, &osnova1, &osnova2);

  /* Ispis rezultata. */
  unsigned dekadna_vrednost = u_dekadni_sistem(broj, osnova1);
  printf("Dekadna vrednost broja %s: %u\n", broj, dekadna_vrednost);

  iz_dekadnog_sistema(dekadna_vrednost, osnova2, broj2);
  printf("Zapis broja %u u osnovi %u: %s\n", dekadna_vrednost,
         osnova2, broj2);

  exit(EXIT_SUCCESS);
}
