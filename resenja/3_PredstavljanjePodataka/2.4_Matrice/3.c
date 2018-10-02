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

void razmeni(int mat[][MAX], int m, int n, int k, int t)
{
	int j, pom;

	for(j = 0; j< n; j++)
	{
		pom = mat[k][j];
		mat[k][j] = mat[t][j];
		mat[t][j] = pom;
	}
}

int main()
{
  int mat[MAX][MAX];
	int m, n;
	int k, t;

	ucitavanje(mat, &m, &n);
	
	printf("Uneti indekse vrsta: ");
	scanf("%d%d", &k, &t);

	if (k < 0 || k >= m || t < 0 || t>= m)
	{
		printf("Neispravni indeksi vrsta.\n");
		return -1;
	}

	razmeni(mat, m, n, k, t);

	ispis(mat, m, n);

	return 0;
}
