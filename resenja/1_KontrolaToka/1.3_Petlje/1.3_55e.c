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
    /* Posle belina se ispisuje sam troougao. Ako je brojac na ivici onda
     * se ispisuje karakter *, a inace praznina. Takodje, proverava se
     * da li se ispisuje poslednji red (i==n) i u njemu se ispisuje
     * svaki drugi put *, a inace praznina. Kako se ispisuje svaki drugi put
     * vrsi se provera j%2 == 0. */
    for (j=0;j<2*i+1;j++)
      if (j==0 || j==2*i || (i==n-1 && j%2==0))
	printf("*");
      else
	printf(" ");
    printf("\n");        
  }
  
  /*Sada se ispisuje donji trougao. Kako je prvi red donjeg trougla
   * vec ispisan (poslednji red gornjeg trougla), potrebno je naciniti jednu
   * iteraciju manje. */
  
  for (i=n-2; i>= 0;i--)
  { 
    /* Prvo se ispisuju beline koje prethode karakterima *. */
    for (j=0;j<n-i-1;j++)
      printf(" ");
    /* Posle belina se ispisuje potreban broj karaktera *. */
    for (j=0;j<2*i+1;j++)
      if (j==0 || j==2*i)
	printf("*");
      else
	printf(" ");
    printf("\n");
  }
 
 return 0;
}