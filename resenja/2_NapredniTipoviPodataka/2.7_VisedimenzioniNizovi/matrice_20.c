#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(double a[][MAKS], int m, int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%lf", &a[i][j]);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  double a[MAKS][MAKS];
  int m, n, k, i, j, indeks_kolone;
  double maks_kolone, min_vrste;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta i broj kolona matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, m, n);

  /* Pronalazak elemenata koji su sedlo. */
  for (i = 0; i < m; i++) {
    /* Pronalazi se najmanji element u tekucoj vrsti. Pamti se
       kolona kojoj taj element pripada. */
    min_vrste = a[i][0];
    indeks_kolone = 0;

    for (j = 1; j < n; j++)
      if (a[i][j] < min_vrste) {
        min_vrste = a[i][j];
        indeks_kolone = j;
      }

    /* Pronalazi se najveci element u zapamcenoj koloni. */
    maks_kolone = a[0][indeks_kolone];

    for (k = 1; k < m; k++)
      if (a[k][indeks_kolone] > maks_kolone)
        maks_kolone = a[k][indeks_kolone];

    /* Element je sedlo ukoliko je on istovremeno najmanji u svojoj
       vrsti i najveci u svojoj koloni. */
    if (min_vrste == maks_kolone)
      printf("Sedlo: %d %d %g\n", i, indeks_kolone, min_vrste);
  }

  exit(EXIT_SUCCESS);
}
