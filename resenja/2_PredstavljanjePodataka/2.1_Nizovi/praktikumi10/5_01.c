#include <stdio.h>

#define MAX 100

int main()
{
  float brojevi[MAX];
  int n, i;

  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);

  if(n<1 || n>100)
  {
    printf("Greska: pogresan unos!\n");
  }else{

  printf("Unesite elemente niza:\n");
  for(i=0;i<n;i++)
    scanf("%f", &brojevi[i]);

  /*
    Ukoliko je i element niza brojevi[i] negativan broj,
    kvadriramo ga tako sto ga pomnozimo sa samim sobom.
  */

  for(i=0;i<n;i++)
    if(brojevi[i]<0)
      brojevi[i] *= brojevi[i];

  /* Ispisujemo sve elemente niza. */

  for(i=0;i<n;i++)
    printf("%g ", brojevi[i]);
}
  return 0;
}
