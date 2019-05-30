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

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int n, i, j, m, x, y, p, k;
  int suma;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta i broj kolona matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, m, n);

  /* Ucitavanje brojeva p i k i provera ispravnosti ulaza. */
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &p, &k);
  if (p <= 0 || p > m || k <= 0 || k > n) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Racunanje i ispis rezultata. */
  printf("Sume podmatrica su: ");
  for (i = 0; i <= m - p; i++) {
    for (j = 0; j <= n - k; j++) {
      /* Za svaku poziciju (i,j), racunana se suma podmatrice
         dimenzije pxk, ciji je gornji levi ugao a[i][j]. */
      suma = 0;
      for (x = 0; x < p; x++)
        for (y = 0; y < k; y++)
          suma += a[i + x][j + y];

      printf("%d ", suma);
    }
  }
  printf("\n");

  return 0;
}
