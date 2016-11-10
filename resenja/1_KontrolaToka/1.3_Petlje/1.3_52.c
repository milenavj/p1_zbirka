#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  for (i=0; i<n; i++)
  {   
    /* Veliko slovo X se moze posmatrati kao dijagonale
     * kvadrata (glavna i sporedna). Zato, treba ispisivati
     * blanko na mestima gde nije dijagonala, a 
     * karakter * na mestima gde je neka od dijagonala.
    */
    for (j=0;j<n;j++)
      /* Provera da li je mesto glavne ili sporedne dijagonale. */
      if (i == j || i+j == n-1)
	printf("*");
      else
	printf(" ");
    printf("\n");        
  }
 
 return 0;
}