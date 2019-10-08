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

#define MAKS_NISKA 101

/* Funkcija ucitava liniju maksimalne duzine n i upisuje je u s.
   Funkcija ne smesta znak za novi red na kraj linije. */
void ucitaj_liniju(char s[], int n) {
  int i = 0, c;

  while ((c = getchar()) != '\n' && i < n - 1 && c != EOF) {
    s[i] = c;
    i++;
  }

  s[i] = '\0';
}

/* Funkcija vraca pokazivac na prvo pojavljivanje niske t u okviru
   niske s ili NULL ukoliko se t ne nalazi u s.

   Trazeni rezultat moze se dobiti koriscenjem funkcije strstr cija 
   se deklaracija nalazi u zaglavlju string.h. Funkcija
   strstr_klon predstavlja jednu mogucu implementaciju ove
   funkcije. */
char *strstr_klon(char s[], char t[]) {
  int i, j;

  /* Spoljasnja petlja ide redom po niski s. */
  for (i = 0; s[i] != '\0'; i++) {
    /* Unutrasnja petlja ide redom po niski t pomocu brojaca j i
       proverava da li se cela niska t poklapa sa delom niske s
       koji pocinje na poziciji i.
       Cim se naidje na situaciju da se karakteri ne poklapaju,
       izlazi se iz unutrasnje petlje. */
    for (j = 0; t[j] != '\0'; j++)
      if (s[i + j] != t[j])
        break;

    /* Ako je unutrasnja petlja dosla do kraja niske t, to znaci
       da su se svi karakteri iz t poklopili sa karakterima iz s i
       t je podniska od s. Kao povratna vrednost se vraca adresa
       gde t pocinje u s. */
    if (t[j] == '\0')
      return &s[i];
  }

  return NULL;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char linija[MAKS_NISKA];
  int i, bar_jedna = 0;

  /* Ucitavanje linija i ispis rednih brojeva linija koje sadrze
     rec "program". */
  printf("Unesite pet linija:\n");
  for (i = 1; i <= 5; i++) {
    ucitaj_liniju(linija, MAKS_NISKA);
    if (strstr_klon(linija, "program") != NULL) {
      if(!bar_jedna)
        printf("Rezultat: ");
      printf("%d ", i);
      bar_jedna = 1;
    }
    /* II nacin: Koriscenjem funkcije strstr cija se deklaracija
       nalazi u zaglavlju string.h.
       if(strstr(linija, "program") != NULL){ 
         printf("%d ", i); 
         bar_jedna = 1; 
       } */
  }
  printf("\n");

  /* Ako indikator bar_jedna i dalje ima vrednost 0, znaci da nije
     uneta nijedna linija koja sadrzi rec "program". */
  if (!bar_jedna)
    printf("Nijedna linija ne sadrzi nisku program.\n");

  exit(EXIT_SUCCESS);
}
