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

#define MAKS_NISKA 21
#define MAKS_N 10
/* Rezultat se dobija nadovezivanjem niske maksimalne duzine
   MAKS_NISKA-1 i karaktera '-' najvise MAKS_N puta. Odavde je
   maksimalna duzina rezultata: (MAKS_NISKA - 1 + 1) * MAKS_N =
   MAKS_NISKA*MAKS_N. Na ovo treba dodati jos 1 karakter zbog
   terminirajuce nule. */
#define MAKS_REZULTAT (MAKS_NISKA*MAKS_N + 1)

int main() {
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA], t[MAKS_REZULTAT];
  int i, n;

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ucitavanje broja ponavljanja i provera ispravnosti ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS_N) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Formiranje rezultata. Prvi karakter rezultujuce niske se
     postavlja na terminirajucu nulu. Ovo se radi jer strcat
     funkcionise tako sto krene od pocetka niske, ide do 
     terminirajuce nule i zatim pocevsi od tog mesta nadovezuje 
     nisku koja je prosledjena kao drugi argument. Na ovaj nacin 
     je obezbedjeno da ce prvi poziv funkcije strcat krenuti da 
     nadovezuje od pocetka niske t. U petlji se na t nadovezuje prvo 
     niska s, a zatim niska "-". Ovo se ponavlja n-1 puta jer nakon  
     poslednjeg nadovezivanja niske s ne treba da se nadje "-". Iz   
     tog razloga se po zavrsetku petlje vrsi jos jedno nadovezivanje
     niske s, ali ne i niske "-". */
  t[0] = '\0';
  for (i = 0; i < n - 1; i++) {
    strcat(t, s);
    strcat(t, "-");
  }
  strcat(t, s);

  /* Ispis rezultata. */
  printf("Rezultujuca niska: %s\n", t);

  exit(EXIT_SUCCESS);
}
