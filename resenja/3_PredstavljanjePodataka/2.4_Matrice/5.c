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

int refleksivna(int a[][MAX], int n)
{
	int i;

	for(i=0; i<n; i++)
		if (a[i][i] != 1)
			return 0;
	
	return 1;
}

int simetricna(int a[][MAX], int n)
{
	int i, j;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			if (a[i][j] != a[j][i])
				return 0;

	return 1;
}

int tranzitivna(int a[][MAX], int n)
{
	int i, j, k;

	for(i=0; i<n; i++)
		for(j=0; j<n; j++)
			for(k=0; k<n; k++)
				if (a[i][j] == 1 && a[j][k] == 1 && a[i][k] == 0)
					return 0;

	return 1;
}

int ekvivalencija(int a[][MAX], int n)
{
	if (refleksivna(a, n) && simetricna(a, n) && tranzitivna(a, n))
		return 1;

	return 0;
}

int main()
{
	int a[MAX][MAX];
	int n;

	ucitavanje(a, &n);

	if (refleksivna(a, n))
		printf("Relacija jeste refleksivna.\n");
	else
		printf("Relacija nije refleksivna.\n");

	if (simetricna(a, n))
		printf("Relacija jeste simetricna.\n");
	else
		printf("Relacija nije simatricna.\n");

	if (tranzitivna(a, n))
		printf("Relacija jeste tranzitivna.\n");
	else
		printf("Relacija nije tranzitivna.\n");

	if (ekvivalencija(a, n))
		printf("Relacija jeste ekvivalencija.\n");
	else
		printf("Relacija nije ekvivalencija.\n");

	return 0;
}
