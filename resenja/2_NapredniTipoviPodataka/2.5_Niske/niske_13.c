#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija kopira prvih n karaktera niske s u nisku t. */
void kopiraj_n(char t[], char s[], int n) {
  int i;
  /* Kopiranje se vrsi ili dok se ne dodje do terminirajuce nule u s
     ili dok se ne prekopira n karaktera. */
  for (i = 0; i < n && s[i] != '\0'; i++)
    t[i] = s[i];

  /* Na kraju rezultujuce niske se upisuje terminirajuca nula. */
  t[i] = '\0';
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n;
  char s[MAKS_NISKA], t[MAKS_NISKA];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ucitavanje broja n i provera ispravnosti ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS_NISKA - 1) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Formiranje rezultata. */
  kopiraj_n(t, s, n);

  /* II nacin: Koriscenjem funkcije strncpy(t, s, n), cija se
     deklaracija nalazi u zaglavlju string.h, kopira najvise n
     karaktera niske s u nisku t.

     strncpy(t,s,n); */

  /* Ispis rezultata. */
  printf("Rezultujuca niska: %s\n", t);

  exit(EXIT_SUCCESS);
}
