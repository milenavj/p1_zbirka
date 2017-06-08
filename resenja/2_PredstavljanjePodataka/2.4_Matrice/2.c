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

void transponovana(int a[][MAX], int m, int n, int b[][MAX])
{
	int i, j;

	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
			b[j][i] = a[i][j];
}

int main()
{
   int mat[MAX][MAX], t[MAX][MAX];
	int m, n;

	ucitavanje(mat, &m, &n);
	transponovana(mat, m, n, t);
	ispis(t, n, m);

	return 0;
}
