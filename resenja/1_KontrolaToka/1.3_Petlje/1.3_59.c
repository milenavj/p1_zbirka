#include <stdio.h>

int main()
{
  unsigned int n;
  int i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);
  
  /* Potrebno je spojiti sve slike u jednu, sliku gornjeg dela romba
   * i sliku donjeg dela romba. */

    /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i=0; i<n; i++)
  { 
    /* Prvo se ispisuju * koje prethode karakterima -. */
    for (j=0;j<n-i;j++)
      printf("*");
    /* Posle * se ispisuje potreban karakter -. */
    for (j=0;j<2*i;j++)
      printf("-");
    /* Potom se ispisuju * koje su nakon karaktera -. */
    for (j=0;j<n-i;j++)
      printf("*");
    printf("\n");        
  }
  
  /*Sada se ispisuje donji trougao. Kako je prvi red donjeg trougla
   * vec ispisan (poslednji red gornjeg trougla), potrebno je naciniti jednu
   * iteraciju manje. */
  
  /* Brojac i odredjuje koliko redova se ispisuje. 
   * Radi lakseg izracunavanja koliko zvezdica i praznina
   * je potrebno ispisati u svakom redu, i se postavlja na 
   * n-1 i smanjuje u svakoj iteraciji petlje. */
  for (i=n-2; i>= 0;i--)
  { 
    /* Prvo se ispisuju * koje prethode karakterima -. */
    for (j=0;j<n-i;j++)
      printf("*");
    /* Posle * se ispisuje potreban karakter -. */
    for (j=0;j<2*i;j++)
      printf("-");
    /* Potom se ispisuju * koje su nakon karaktera -. */
    for (j=0;j<n-i;j++)
      printf("*");
    printf("\n");
  }
 
 return 0;
}