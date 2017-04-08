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

int main()
{
	int a[MAX][MAX];
	int n, i, j;
	int max_zbir, trenutni_zbir = 0, indeks_kolone = 0;

	ucitaj(a, &n);

	for(i=0; i<n; i++)
		trenutni_zbir += a[i][0];

	max_zbir = trenutni_zbir;

	for(j=1; j<n; j++)
	{

		trenutni_zbir = 0;
		for(i=0; i<n; i++)
			trenutni_zbir += a[i][j];

		if (trenutni_zbir > max_zbir)
		{
			max_zbir = trenutni_zbir;
			indeks_kolone = j;
		}
	}

	printf("Indeks kolone je: %d\n", indeks_kolone);

	return 0;
}
