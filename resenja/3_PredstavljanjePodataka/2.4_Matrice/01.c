#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int m, n;
  int i, j;

  /* Ucitavanje dimenzija matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenzije matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);

  /* Ispis elemenata matrice. */
  for (i = 0; i < m; i++) 
  {
    for (j = 0; j < n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }

  return 0;
}
