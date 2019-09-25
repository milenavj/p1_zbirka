#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija sabira elemenate niza od pozicije i do pozicije j. */
int zbir(int a[], int i, int j) {
  int k, rezultat = 0;

  /* Obilazak elemenata niza koji pripadaju zadatom opsegu. */
  for (k = i; k <= j; k++)
    rezultat += a[k];

  return rezultat;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, i, j;
  int a[MAKS];

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n);

  /* Ucitavanje vrednosti granica i provera ispravnosti ulaza. */
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
