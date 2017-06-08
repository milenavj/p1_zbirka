#include <stdio.h>
#include <stdlib.h>

#define MAX 50

int main()
{
  int mat[MAX][MAX];
  int m, n;

	int i, j;

  printf("Uneti dimenzije matrice: ");
  scanf("%d%d", &m, &n);

  if (n <= 0 || n > MAX || m <= 0 || m > MAX)
  {
    printf("Neispravna dimenzija matrice\n");
    exit(EXIT_FAILURE);
  }

  printf("Uneti matricu celih brojeva\n");

  for(i=0; i<m; i++)
    for(j=0; j<n; j++)
      scanf("%d", &mat[i][j]);

  /* Ispis elemenata matrice. */
  for(i=0; i<m; i++)
  {
    for(j=0; j<n; j++)
      printf("%d ", mat[i][j]);
    printf("\n");
  }		

  return 0;
}
