#include <stdio.h>

int main()
{
  unsigned int n, i, j;
  
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Brojac koji broji koliko brojeva je ispisano
   * u jednom redu. */
  j = 0;
  for (i=1;i<=n*n;i++)
  {
    printf("%3d ", i); 
    /* Uvecavamo brojac */
    j++;
	
    /* Kada je ispisano n brojeva u jednom redu,
     * ispisuje se znak za novi red, da bi ispis 
     * krenuo u novom redu i vrednost brojaca j 
     * se postavlja na 0 jer u novom redu jos ni 
     * jedan broj nije ispisan. */
    if (j==n)
    {
      j = 0;
      printf("\n"); 
    }
  }
  
  return 0;
}