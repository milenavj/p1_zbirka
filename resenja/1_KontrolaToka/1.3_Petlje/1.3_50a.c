#include <stdio.h>

int main()
{
  unsigned int n, i, j;
  
  printf("Unesite broj n: ");
  scanf("%u", &n);

  for (i=1;i<=n;i++)
  {
    for (j=1; j<=n; j++)
    /* U tablici mnozenja vrednost svakog polja je proizvod
     * vrste i kolone u kojoj se nalazi. */
      printf("%3d ", i*j);    
					    
    printf("\n");        
  }
  
  return 0;
}