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

int main()
{
    float a[MAX][MAX];
    int n, i, j;
    float gornji_trougao = 0, donji_trougao = 0;

    ucitavanje(a, &n);

    for(i=0; i<n/2; i++)
      for(j=i+1; j<n-i-1; j++)
        gornji_trougao += a[i][j];
        
    for(i=n/2; i<n; i++)
      for(j=n-i; j<i; j++)
        donji_trougao += a[i][j];
        
    printf("%f %f\n", gornji_trougao, donji_trougao);

    printf("Razlika je: %.2f\n", gornji_trougao - donji_trougao);

    return 0;
}
