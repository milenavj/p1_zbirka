#include <stdio.h>

#define MAX 100

int main()
{
  float brojevi[MAX];
  int n, i;

  /* Ucitava se dimenzija niza i proverava se njena ispravnost. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if(n<1 || n>MAX)
  {
    printf("Nedozvoljena vrednost!\n");
    return -1;
  }
 
  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:\n");  	
  for(i=0;i<n;i++){
  	scanf("%f", &brojevi[i]);
  }
  
  /* Ukoliko je i-ti element niza brojevi[i] negativan broj, kvadrira se tako sto se pomnozi sa samim sobom. */	
  for(i=0;i<n;i++){
    if(brojevi[i]<0)
      brojevi[i] *= brojevi[i];
  }

  /* Ispisuje se novodobijeni niz. */
  for(i=0;i<n;i++){
    printf("%g ", brojevi[i]);
  }
  printf("\n");
	
  return 0;
}
