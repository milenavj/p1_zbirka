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

void ispis(int mat[][MAX], int m, int n)
{
	int i, j;

	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
			printf("%d ", mat[i][j]);
		printf("\n");
	}		
}

void mnozenje(int a[][MAX], int m, int n, int b[][MAX], int k, int t, int c[][MAX])
{
  int i, j, w;
    
  for(i=0; i<m; i++)
    for(j=0; j<t; j++)
    {
      c[i][j] = 0;
      for(w=0; w<n; w++)
        c[i][j] += a[i][w] * b[w][j];
    }
}

int main()
{
  int a[MAX][MAX], b[MAX][MAX], c[MAX][MAX];
  int m, n;
  int k, t;
  
  ucitavanje(a, &m, &n);
  ucitavanje(b, &k, &t);
  
  if (n != k)
  {
    printf("Mnozenje matrica nije moguce.\n");
    return -1;
  }
  
  mnozenje(a, m, n, b, k, t, c);
  
  printf("Rezultat mnozenja je:\n");
  ispis(c, m, t);
  
  return 0;

}
