#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja racuna zbir elemenata niza od pozicije i do 
   pozicije j. */
int zbir(int a[], int i, int j)
{
  int k;
  int rezultat = 0;

  /* Obilaze se elementi niza iz zadatog opsega. */
  for (k = i; k <= j; k++) {
    rezultat += a[k];
  }

  /* Vraca se izracunata vrednost. */
  return rezultat;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i, j;
  int a[MAKS];

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  /* Ucitavaju se vrednosti granica i vrsi se provera
     ispravnosti ulaza. */
  printf("Unesite vrednosti za i i j: ");
  scanf("%d%d", &i, &j);
  if (i < 0 || j < 0 || i > n - 1 || j > n - 1 || i > j) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ispis rezultata. */
  printf("Zbir je: %d", zbir(a, i, j));

  exit(EXIT_SUCCESS);
}
