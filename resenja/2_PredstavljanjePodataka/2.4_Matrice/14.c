#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void ucitavanje(int mat[][MAX], int* n)
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

int suma_kolone(int mat[][MAX], int n, int j)
{
  int i, suma = 0;
  
  for(i=0; i<n; i++)
    suma += mat[i][j];
  
  return suma;
}

int suma_vrste(int mat[][MAX], int n, int i)
{
  int j, suma = 0;
  
  for(j=0; j<n; j++)
    suma += mat[i][j];
  
  return suma;
}

int magicni_kvadrat(int mat[][MAX], int n)
{
  int suma = suma_kolone(mat, n, 0);
  int i, j;
  
  for(j=1; j<n; j++)
    if (suma_kolone(mat, n, j) != suma)
      return 0;
  
  for(i=0; i<n; i++)
    if (suma_vrste(mat, n, i) != suma)
      return 0;
    
  return 1;
}

int main()
{
  int mat[MAX][MAX];
  int n;
    
  ucitavanje(mat, &n);
  
  if (magicni_kvadrat(mat, n))
    printf("Matrica jeste magicni kvadrat.\n");
  else
    printf("Matrica nije magicni kvadrat.\n");
  
  return 0;
}
