#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija koja racuna najmanji i najveci element niza a. */
void min_max(float a[], int n, float *najmanji, float *najveci)
{
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

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int i, n;
  float a[MAKS], min, max;

  /* Ucitava se dimenzija niza. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n < 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:\n");
  for (i = 0; i < n; i++)
    scanf("%f", &a[i]);

  /* Racunaju se vrednosti najmanjeg i najveceg elementa. */
  min_max(a, n, &min, &max);

  /* Ispis rezultata. */
  printf("Najmanji: %.3f\n", min);
  printf("Najveci: %.3f\n", max);

  exit(EXIT_SUCCESS);
}