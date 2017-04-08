#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void ucitaj(int mat[][MAX], int* n)
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

int donje_trougaona(int a[][MAX], int n)
{
	int i, j;

	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			if (a[i][j] != 0)
				return 0;

	return 1;
}

int main()
{
	int a[MAX][MAX];
	int n;

	ucitaj(a, &n);

	if (donje_trougaona(a, n))
		printf("Matrica jeste donje trougaona.\n");
	else
		printf("Matrica nije donje trougaona.\n");

	return 0;
}
