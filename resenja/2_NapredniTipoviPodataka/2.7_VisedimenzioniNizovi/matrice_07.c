#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int m, int n) {
  int i, j;

  printf("Unesite elemente matrice:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

/* Funkcija formira niz b tako sto element b[i] ima vrednost
   prosecne vrednosti i-te vrste matrice. */
void kreiraj_niz(int a[][MAKS], int m, int n, double b[]) {
  int i, j, suma;

  for (i = 0; i < m; i++) {
    suma = 0;
    for (j = 0; j < n; j++)
      suma += a[i][j];

    b[i] = (double) suma / n;
  }
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  double b[MAKS];
  int m, n, i;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta i broj kolona matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, m, n);

  /* Formiranje niza b. */
  kreiraj_niz(a, m, n, b);

  /* Ispis rezultata. */
  printf("Dobijeni niz je:\n");
  for (i = 0; i < m; i++)
    printf("%g ", b[i]);
  printf("\n");

  return 0;
}
