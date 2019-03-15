#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije m*n. */
void ucitaj(int a[][MAKS], int m, int n)
{
  int i, j;
  
  printf("Unesite elemente matrice:\n");
  for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      scanf("%d", &a[i][j]);
}

/* Funkcija ispisuje elemente matrice dimenzije m*n. */
void ispisi(int a[][MAKS], int m, int n)
{
  int i, j;

  for(i=0; i<m; i++)
  {
    for(j=0; j<n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }     
}

/* Funkcija razmenjuje elemente k-te i t-te vrste. */
void razmeni(int a[][MAKS], int m, int n, int k, int t)
{
  int j, pom;

  for(j = 0; j< n; j++)
  {
      pom = a[k][j];
      a[k][j] = a[t][j];
      a[t][j] = pom;
  }
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int m, n;
  int k, t;

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
  
  /* Ucitavanje indeksa vrsta i provera ispravnosti ulaza. */
  printf("Unesite indekse vrsta: ");
  scanf("%d%d", &k, &t);
  if (k < 0 || k >= m || t < 0 || t>= m)
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Razmena k-te i t-te vrste. */
  razmeni(a, m, n, k, t);

  /* Ispis rezultata. */
  ispisi(a, m, n);

  return 0;
}
