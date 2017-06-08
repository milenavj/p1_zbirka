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

int podmatrica(int a[][MAX], int m, int n, int b[][MAX], int k, int t)
{
  int i, j, x, y;
  int jeste_pod;
  
  for(i=0; i<= m-k; i++)
    for(j=0; j<= n-t; j++)
    {
      jeste_pod = 1;
      for(x=0; x<k && jeste_pod; x++)
        for(y=0; y<t && jeste_pod; y++)
          if (a[i+x][j+y] != b[x][y])
            jeste_pod = 0;
          
      if (jeste_pod)
        return 1;
    }
    
  return 0;
}

int main()
{
  int a[MAX][MAX], b[MAX][MAX];
  int m, n;
  int k, t;
  
  ucitavanje(a, &m, &n);
  ucitavanje(b, &k, &t);
  
  if (podmatrica(a, m, n, b, k, t))
    printf("Druga matrica je sadrzana u prvoj matrici.\n");
  else
    printf("Druga matrica nije sadrzana u prvoj matrici.\n");
  
}
  
