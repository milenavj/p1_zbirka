#include <stdio.h>
#include <stdlib.h>

#define MAX 200

void ucitaj(int mat[][MAX], int* n)
{
  int i, j;

  printf("Uneti dimenzije matrice: ");
  scanf("%d", n);

  if (*n <= 0 || *n > MAX)
  {
    printf("Neispravna dimenzija matrice\n");
    exit(EXIT_FAILURE);
  }

  printf("Uneti matricu celih brojeva\n");

  for(i=0; i<*n; i++)
    for(j=0; j<*n; j++)
      scanf("%d", &mat[i][j]);
}

int skalarni_proizvod(int mat[][MAX], int n, int i, int j)
{
  int suma = 0, k;
  
  for(k=0; k<n; k++)
    suma += mat[i][k] * mat[j][k];
  
  return suma;
}

int ortonormirana(int mat[][MAX], int n)
{
  int i, j;
  
  for(i=0; i<n; i++)
    for(j=0; j<n; j++)
      if (i==j && skalarni_proizvod(mat, n, i, i) != 1)
        return 0;
      else if (i != j && skalarni_proizvod(mat, n, i, j) != 0)
        return 0;
      
  return 1;
}

int main()
{
  int mat[MAX][MAX];
  int n;
    
  ucitaj(mat, &n);
  
  if (ortonormirana(mat, n))
    printf("Matrica jeste ortonormirana.\n");
  else
    printf("Matrica nije ortonormirana.\n");
 
  return 0;
}