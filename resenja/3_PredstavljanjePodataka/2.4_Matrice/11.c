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

int sortirana_kolona(int mat[][MAX], int n, int j)
{
  int i;
  
  for(i=0; i<n-1; i++)
    if (mat[i][j] >= mat[i+1][j])
      return 0;
    
  return 1;
}

int sortirani_po_kolonama(int mat[][MAX], int n)
{
  int j;
    
  for(j=0; j<n; j++)
    if (!sortirana_kolona(mat, n, j))
      return 0;
        
  return 1;
}

int sortirana_vrsta(int mat[][MAX], int n, int i)
{
  int j;
  
  for(j=0; j<n-1; j++)
    if (mat[i][j] >= mat[i][j+1])
      return 0;
    
  return 1;
}

int sortirani_po_vrstama(int mat[][MAX], int n)
{
  int i;
    
  for(i=0; i<n; i++)
    if (!sortirana_vrsta(mat, n, i))
      return 0;
        
  return 1;
}

int sortirana_glavna(int mat[][MAX], int n)
{
  int i;
  
  for(i=0; i<n-1; i++)
    if (mat[i][i] >= mat[i+1][i+1])
      return 0;
    
  return 1;
}

int sortirana_sporedna(int mat[][MAX], int n)
{
  int i;
  
  for(i=0; i<n-1; i++)
    if (mat[i][n-i-1] >= mat[i+1][n-i-2])
      return 0;
    
  return 1;
}

int sortirani_po_dijagonalama(int mat[][MAX], int n)
{
  if (!sortirana_glavna(mat, n))
    return 0;
  
  if (!sortirana_sporedna(mat, n))
    return 0;
        
  return 1;
}

int main()
{
  int mat[MAX][MAX];
  int n;
    
  ucitavanje(mat, &n);
  
  if (sortirani_po_kolonama(mat, n))
	  printf("Elementi su sortirani po kolonama.\n");
	else
		printf("Elementi nisu sortirani po kolonama.\n");

	if (sortirani_po_vrstama(mat, n))
	  printf("Elementi su sortirani po vrstama.\n");
	else
		printf("Elementi nisu sortirani po vrstama.\n");

	if (sortirani_po_dijagonalama(mat, n))
	  printf("Elementi su sortirani po dijagonalama.\n");
	else
		printf("Elementi nisu sortirani po dijagonalama.\n");

  return 0;
}
