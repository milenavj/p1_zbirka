#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void ucitaj(int mat[][MAX], int* m, int* n)
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
  int m, n, brojac, i, j;
  
  int pravac = 1;
  int gore_i, dole_i, levo_j, desno_j;

  ucitaj(mat, &m, &n);
  
  gore_i = 1;
  dole_i = m-1;
  
  levo_j = 0;
  desno_j = n-1;
  
  i = 0;
  j = 0;
  
  for(brojac=0; brojac < m*n; brojac++)
  {
    printf("%d ", mat[i][j]);
    
    switch(pravac)
    {
      case 1: 
        if (j == desno_j)
        {
          pravac = 2;
          desno_j--;
          i++;
        }
        else
          j++;
        break;
      case 2:
        if (i == dole_i)
        {
          pravac = 3;
          dole_i--;
          j--;
        }
        else
          i++;
        break;
      case 3:
        if (j == levo_j)
        {
          pravac = 4;
          levo_j++;
          i--;
        }
        else
          j--;
        break;
      case 4:
        if (i == gore_i)
        {
          pravac = 1;
          gore_i++;
          j++;
        }
        else
          i--;
    }
  }

  return 0;
}