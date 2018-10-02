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
	int a[MAX][MAX];
	int n, i, j, m, x, y, p, k;
	int suma;

	ucitavanje(a, &m, &n);

	printf("Uneti dva cela broja: ");
    scanf("%d%d", &p, &k);
    
    printf("Sume podmatrica su: ");
    for(i=0; i<= m-p; i++)
      for(j=0; j<= n-k; j++)
      {
        suma = 0;
        for(x=0; x<p; x++)
          for(y=0; y<k; y++)
            suma += a[i+x][j+y];
          
        printf("%d ", suma);
      }
      
    printf("\n");

	return 0;
}
