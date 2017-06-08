#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void ucitavanje(int mat[][MAX], int* m, int* n)
{
  int i, j;

  printf("Uneti dimenzije matrice: ");
  scanf("%d%d", m, n);

  if (*n <= 0 || *n > MAX || *m <= 0 || *m > MAX)
  {
    printf("Neispravna dimenzija matrice\n");
    exit(EXIT_FAILURE);
  }

  printf("Uneti matricu celih brojeva\n");

  for(i=0; i<*m; i++)
    for(j=0; j<*n; j++)
      scanf("%d", &mat[i][j]);
}

void kreiraj_niz(int mat[][MAX], int m, int n, double b[])
{
  int i, j, suma;
  
  for(i=0; i<m; i++)
  {
    suma = 0;
    for(j=0; j<n; j++)
      suma += mat[i][j];
    
    b[i] = (double)suma/n;
  }
}

int main()
{
  int mat[MAX][MAX];
  double  b[MAX];
  int m, n, i;

  ucitavanje(mat, &m, &n);
  
  kreiraj_niz(mat, m, n, b);
  
  printf("Dobijeni niz je:\n");
  for(i=0; i<m; i++)
    printf("%g ", b[i]);
  printf("\n");
  
  return 0;
}
