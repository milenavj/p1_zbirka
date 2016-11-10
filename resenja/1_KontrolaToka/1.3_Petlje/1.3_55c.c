#include <stdio.h>

int main()
{
  unsigned int n;
  int i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

    /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i=0; i<n; i++)
  { 
    /* Prvo se ispisuju beline koje prethode karakterima *. */
    for (j=0;j<n-i-1;j++)
      printf(" ");
    /* Posle belina se ispisuje potreban broj karaktera *. */
    for (j=0;j<2*i+1;j++)
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
    /* Prvo se ispisuju beline koje prethode karakterima *. */
    for (j=0;j<n-i-1;j++)
      printf(" ");
    /* Posle belina se ispisuje potreban broj karaktera *. */
    for (j=0;j<2*i+1;j++)
      printf("*");
    printf("\n");
  }
 
 return 0;
}