#include <stdio.h>

int main()
{
  unsigned int n, m;
  int i, j, k;

  printf("Unesite brojeve n i m: ");
  scanf("%u%u", &n, &m);
  
  for(i=1; i<=m; i++)
  {
    /* Za svaki kvadrat se racuna duzina bez poslednje ivice.
     * Kvadrat je sastavljen od (m-1) zvezdice i (m-1) praznine 
     * (praznine se nalaze izmedju zvezdica).
     * Znaci ukupna duzina je 2*(m-1) karakter, a kako ima
     * n kvadrata, duzina je n*2*(m-1). */
    for(j=0; j<= n*2*(m - 1); j++)
      /* Provera da li se ispisuje prvi ili poslednji red. */
      if (i == 1 || i == m)
	/* Naizmenicno se ispisuje * i praznina. */
	if (j%2 == 0)
	  printf("*");
	else
	  printf(" ");
      else
	/* Na kraju svakog kvadrata (nakon svake (m-1) zvezdice i  
	 * (m-1) praznine se ispisuje ivica kvadrata. */
	if (j%(2*(m-1)) == 0)
	  printf("*");
	else
	  printf(" ");
	
      printf("\n");
  }
  
  return 0;
}