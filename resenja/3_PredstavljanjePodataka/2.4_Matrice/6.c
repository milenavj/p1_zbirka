#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void ucitavanje(float mat[][MAX], int* n)
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
			scanf("%f", &mat[i][j]);
}

float trag(float a[][MAX], int n)
{
	float suma = 0;
	int  i;

	for(i=0; i<n; i++)
		suma += a[i][i];

	return suma;
}

float suma_sporedna(float a[][MAX], int n)
{
	float suma = 0;
	int  i;
	
	for(i=0; i<n; i++)
		suma += a[i][n-i-1];

	return suma;
}

float suma_iznad(float a[][MAX], int n)
{
	float suma = 0;
	int  i, j;
	
	for(i=0; i<n; i++)
		for(j=i+1; j<n; j++)
			suma += a[i][j];

	return suma;
}

float suma_ispod(float a[][MAX], int n)
{
	float suma = 0;
	int  i, j;
	
	for(i=0; i<n; i++)
		for(j=n-i-1; j>i; j--)
			suma += a[i][j];

	return suma;
}

int main()
{
	float a[MAX][MAX];
	int n;

	ucitavanje(a, &n);

	printf("Trag je %.3f.\n", trag(a, n));
	printf("Suma na sporednoj dijagonali je %.3f.\n", suma_sporedna(a, n));
	printf("Suma iznad glavne dijagonale je %.3f.\n", suma_iznad(a, n));
	printf("Suma ispod sporedne dijagonale je %.3f.\n", suma_ispod(a, n));

	return 0;
}
