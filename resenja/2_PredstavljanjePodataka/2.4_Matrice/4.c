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


int main()
{
  int mat[MAX][MAX];
	int m, n, i, j, suma;
	int k, t;

	ucitavanje(mat, &m, &n);

	printf("Indeksi elemenata koji su jednaki zbiru suseda su:\n");
	for(i=0; i<m; i++)
		for(j=0; j<n; j++)
		{
			suma = 0;

			for(k=-1;k<=1; k++)
				for(t=-1; t<=1; t++)
					if (i+k >= 0 && i+k < n && j+t >= 0 && j+t < n)	
						suma += mat[i+k][j+t];
	
			if (suma - mat[i][j] == mat[i][j])
				printf("%d %d\n", i, j);		
		}

	return 0;
}
