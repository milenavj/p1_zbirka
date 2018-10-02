#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void ucitavanje(double mat[][MAX], int* m, int* n)
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
      scanf("%lf", &mat[i][j]);
}

int main()
{
  double mat[MAX][MAX];
  int m, n, k, i, j;
  
  int indeks_kolone;
  double max_kolone, min_vrste;
  
  ucitavanje(mat, &m, &n);
    
  for(i=0; i<m; i++)
  {
    min_vrste = mat[i][0];
    indeks_kolone = 0;
      
    for(j=1; j<n; j++)
      if (mat[i][j] < min_vrste)
      {
        min_vrste = mat[i][j];
        indeks_kolone = j;
      }
      
    max_kolone = mat[0][indeks_kolone];
    
    for(k=1; k<m; k++)
      if (mat[k][indeks_kolone] > max_kolone)
        max_kolone = mat[k][indeks_kolone];
      
    if (min_vrste == max_kolone)
      printf("Sedlo: %d %d %g\n", i, indeks_kolone, min_vrste);
 
  }
    
  return 0;
}
