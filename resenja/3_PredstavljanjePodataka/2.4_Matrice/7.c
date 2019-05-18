#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

/* Funkcija proverava da li je matrica donje trougaona i vraca
   jedinicu ukoliko jeste, a nulu inace. */
int donje_trougaona(int a[][MAKS], int n) {
  int i, j;

  /* Prolazi se kroz sve elemente iznad glavne dijagonale i ukoliko 
     se naidje na element koji je razlicit od nule, onda matrica
     nije donje trougaona. */
  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      if (a[i][j] != 0)
        return 0;

  /* Ukoliko su svi elementi iznad glavne dijagonale nule, matrica
     jeste donje trougaona. */
  return 1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int n;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenziju matrice: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, n);

  /* Ispis rezultata. */
  if (donje_trougaona(a, n))
    printf("Matrica jeste donje trougaona.\n");
  else
    printf("Matrica nije donje trougaona.\n");

  return 0;
}
