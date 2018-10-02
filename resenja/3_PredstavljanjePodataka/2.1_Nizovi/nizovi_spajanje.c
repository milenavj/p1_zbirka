#include <stdio.h>

#define MAX 100

int main()
{
  int a[MAX], b[MAX], c[2*MAX];
  int i, n;

  /* Ucitava se broj elemenata nizova i proverava se njegova ispravnost. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if(n<1 || n>MAX)
  {
    printf("Greska: Nedozvoljena vrednost!\n");
    return -1;
  }

  /* Ucitavaju se elementi nizova */
  printf("Unesite elemente niza a: ");
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);

  printf("Unesite elemente niza b: ");
  for(i=0;i<n;i++)
    scanf("%d", &b[i]);

  /* Niz c ima 2*n elemenata: prvih n elemenata su elementi niza b, a narednih n elemenata elementi niza a. Elementi niza b se nalaze na pozicijama 0,1,2,...n-1, a elementi niza a na pozicijama n,n+1,...2*n-1. Jednim prolaskom kroz petlju na poziciju i u nizu c se postavlja element b[i] niza b, a na poziciju n+i element a[i] niza a. */
  for(i=0;i<n;i++)
  {
    c[i] = b[i];
    c[n+i] = a[i];
  }

  /* Ispisuju se elementi niza c. */
  for(i=0;i<2*n;i++)
    printf("%d ", c[i]);
  printf("\n");
 
  return 0;
}
