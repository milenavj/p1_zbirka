#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, i;
  int fib1 = 0, fib2 = 1, fib3;
  
  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Ako je n=0, F[0] = 0, slicno ako je n=1 F[1] = 1. */
  if(n < 2){
    printf("F[%d] = %d\n",n, n);
    return 0;
  }
  
  fib3 = fib1 + fib2;
  for(i=2; i<n; i++) {    
    /* Vrsi se pomeranje na sledecu trojku. */
    fib1 = fib2;
    fib2 = fib3;
    fib3 = fib1 + fib2;
  }

  /* Ispis rezultata. */
  printf("F[%d] = %d\n", n, fib3);

  return 0;
}
