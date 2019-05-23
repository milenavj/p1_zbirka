#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija racuna duzinu prefiksa niske t koji se moze zapisati
   pomocu karaktera niske s. Na primer, t="programiranje",
   s="grupacija", rezultat je 2 jer niska s sadrzi prva dva
   karaktera niske t, ali ne i treci.

   Trazeni rezultat moze se dobiti koriscenjem funkcije strspn cija 
   se deklaracija nalazi u zaglavlju string.h. Funkcija
   strspn_klon predstavlja jednu mogucu implementaciju ove
   funkcije. */
int strspn_klon(char t[], char s[]) {
  int i, brojac = 0;

  /* Ide se redom po karakterima niske t i za svaki karakter se
     vrsi provera da li se on nalazi u zapisu niske s. Za ovo se
     koristi funkcija strchr. Ako se nalazi, uvecava se brojac, a
     ako se ne nalazi, prekida se petlja. */
  for (i = 0; t[i]; i++) {
    if (strchr(s, t[i]) != NULL)
      brojac++;
    else
      break;
  }

  return brojac;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA], t[MAKS_NISKA];

  /* Ucitavanje niski. */
  printf("Unesite nisku t: ");
  scanf("%s", t);
  printf("Unesite nisku s: ");
  scanf("%s", s);

  /* Racunanje i ispis rezultata. */
  printf("Rezultat: %d\n", strspn_klon(t, s));

  exit(EXIT_SUCCESS);
}
