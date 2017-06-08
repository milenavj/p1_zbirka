#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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
  int suma = 0, i;
  
  for(i=0; i<n; i++)
    suma += mat[i][j];
  
  return suma;
}

int uredjene_sume(int mat[][MAX], int n)
{
  int suma1, suma2;
  int j;
  
  suma1 = suma_kolone(mat, n, 0);
  
  for(j=1; j<n; j++)
  {
    suma2 = suma_kolone(mat, n, j);
    
    if (suma1 >= suma2)
      return 0;
    
    suma1 = suma2;
  }
  
  return 1;
}

int main()
{
  int mat[MAX][MAX];
  int n;
    
  ucitavanje(mat, &n);
  
  if (uredjene_sume(mat, n))
    printf("Sume jesu uredjenje strogo rastuce.\n");
  else
    printf("Sume nisu uredjenje strogo rastuce.\n");

  
  return 0;
}
