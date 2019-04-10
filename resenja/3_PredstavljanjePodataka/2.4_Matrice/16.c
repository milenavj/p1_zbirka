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

  for (i = 0; i < m; i++) 
  {
    for (j = 0; j < n; j++)
      printf("%d ", a[i][j]);
    printf("\n");
  }
}

/* Funkcija vrsi mnozenje matrica a i b i rezultat smesta u matricu 
   c. */
void mnozenje(int a[][MAKS], int m, int n,
              int b[][MAKS], int k, int t, int c[][MAKS])
{
  int i, j, w;

  for (i = 0; i < m; i++) 
  {
    for (j = 0; j < t; j++) 
    {
      /* Element c[i][j] se dobija kao skalarni proizvod i-te vrste 
         matrice a i j-te kolone matrice b. */
      c[i][j] = 0;
      for (w = 0; w < n; w++)
        c[i][j] += a[i][w] * b[w][j];
    }
  }
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS], b[MAKS][MAKS], c[MAKS][MAKS];
  int m, n;
  int k, t;

  /* Ucitavanje dimenzija prve matrice i provera ispravnosti
     ulaza. */
  printf("Unesite dimenzije matrice A: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata prve matrice. */
  ucitaj(a, m, n);

  /* Ucitavanje dimenzija druge matrice i provera ispravnosti
     ulaza. */
  printf("Unesite dimenzije matrice B: ");
  scanf("%d%d", &k, &t);
  if (k <= 0 || k > MAKS || t <= 0 || t > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Provera da li se odgovarajuce dimenzije matrica poklapaju. */
  if (n != k) 
  {
    printf("Mnozenje matrica nije moguce.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitavanje elemenata druge matrice. */
  ucitaj(b, k, t);

  /* Racunanje proizvoda. */
  mnozenje(a, m, n, b, k, t, c);

  /* Ispis rezultata. */
  printf("Rezultat mnozenja je:\n");
  ispisi(c, m, t);

  return 0;
}
