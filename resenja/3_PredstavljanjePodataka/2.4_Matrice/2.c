#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije m*n. */
void ucitaj(int a[][MAKS], int m, int n)
{
  int i, j;

  printf("Unesite elemente matrice:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

/* Funkcija ispisuje elemente matrice dimenzije m*n. */
void ispisi(int a[][MAKS], int m, int n)
{
  int i, j;

  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}

/* Funkcija formira maticu t transponovanjem matrice a. */
void transponovana(int a[][MAKS], int m, int n, int t[][MAKS])
{
  int i, j;

  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      t[j][i] = a[i][j];
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS], t[MAKS][MAKS];
  int m, n;

  /* Ucitavanje dimenzija matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenzije matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, m, n);

  /* Formiranje transponovane matrice. */
  transponovana(a, m, n, t);

  /* Ispis rezultata. */
  ispisi(t, n, m);

  return 0;
}
