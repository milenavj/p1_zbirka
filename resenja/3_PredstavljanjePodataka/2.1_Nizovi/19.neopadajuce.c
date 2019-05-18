#include <stdio.h>
#include <stdlib.h>

#define MAKS 300

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija proverava da li je niz uredjen neopadajuce. */
int uredjen_neopadajuce(int niz[], int n) {
  int i;
  for (i = 0; i < n - 1; i++)
    if (niz[i] > niz[i + 1])
      return 0;

  return 1;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, niz[MAKS];

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(niz, n);

  /* Ispis rezultata. */
  if (uredjen_neopadajuce(niz, n))
    printf("Niz jeste uredjen neopadajuce.\n");
  else
    printf("Niz nije uredjen neopadajuce.\n");

  exit(EXIT_SUCCESS);
}
