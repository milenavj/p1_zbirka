#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije n*n. */
void ucitaj(float a[][MAKS], int n)
{
  int i, j;
  
  printf("Unesite elemente matrice:\n");
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      scanf("%f", &a[i][j]);
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  float a[MAKS][MAKS];
  int n, i, j;
  float gornji_trougao = 0, donji_trougao = 0;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenziju matrice: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS)
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, n);

  /* Racuna se suma gornjeg trougla. */
  for(i=0; i<n/2; i++)
    for(j=i+1; j<n-i-1; j++)
      gornji_trougao += a[i][j];
      
  /* Racuna se suma donjeg trougla. */
  for(i=n/2; i<n; i++)
    for(j=n-i; j<i; j++)
      donji_trougao += a[i][j];

  /* Ispis rezultata. */
  printf("Razlika je: %.2f\n", gornji_trougao - donji_trougao);

  return 0;
}