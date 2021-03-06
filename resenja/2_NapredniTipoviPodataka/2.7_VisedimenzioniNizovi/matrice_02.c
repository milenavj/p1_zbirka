#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS 50

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int i, j, m, n, suma = 0;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta i broj kolona matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  /* Racunanje sume kvadrata svih elemenata. */
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      suma += a[i][j] * a[i][j];

  /* Ispis rezultata. */
  printf("Euklidska norma: %.3lf\n", sqrt(suma));

  exit(EXIT_SUCCESS);
}
