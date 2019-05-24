#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija racuna najmanji i najveci element niza a duzine n. */
void min_maks(float a[], int n, float *najmanji, float *najveci) {
  int i;

  /* Vrednosti minimuma i maksimuma se inicijalizuju na vrednost
     prvog clana niza. */
  *najmanji = a[0];
  *najveci = a[0];

  /* U petlji se prolazi kroz ostale clanove niza i po potrebi se
     vrsi azuriranje najmanje i najvece vrednosti. */
  for (i = 1; i < n; i++) {
    if (a[i] > *najveci)
      *najveci = a[i];

    if (a[i] < *najmanji)
      *najmanji = a[i];
  }

  /* Na kraju petlje, na adresama najmanji i najveci se nalaze
     trazene vrednosti. */
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int i, n;
  float a[MAKS], min, maks;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  printf("Unesite elemente niza:\n");
  for (i = 0; i < n; i++)
    scanf("%f", &a[i]);

  /* Racunanje vrednosti najmanjeg i najveceg elementa. */
  min_maks(a, n, &min, &maks);

  /* Ispis rezultata. */
  printf("Najmanji: %.3f\n", min);
  printf("Najveci: %.3f\n", maks);

  exit(EXIT_SUCCESS);
}
