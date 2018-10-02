#include <stdio.h>
#include <stdlib.h>

#define MAX 100

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

int main()
{
  int mat[MAX][MAX];
  int n;
  int i, j, k;
    
  ucitavanje(mat, &n);
  
  for(k=0; k<n; k++)
  {
    j = k;
    i = 0;
    
    while(j >= 0)
    {
      printf("%d ", mat[i][j]);
      i++;
      j--;
    }
    
    printf("\n");
  }
  
  
  for(k=1; k<n; k++)
  {
    i = k;
    j = n-1;
    
    while(i < n)
    {
      printf("%d ", mat[i][j]);
      i++;
      j--;
    }
    
    printf("\n");
  }
  
  return 0;
}
