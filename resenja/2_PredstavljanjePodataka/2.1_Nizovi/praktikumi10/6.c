#include <stdio.h>

#define MAX 100

int main()
{
  int a[MAX], b[MAX], c[2*MAX];
  int i, n;

  printf("Unesite broj n: ");
  scanf("%d", &n);

  if(n<1 || n>MAX)
  {
    printf("Greska: pogresan unos!\n");
    return -1;
  }

  printf("Unesite elemente niza a: ");
  for(i=0;i<n;i++)
    scanf("%d", &a[i]);

  printf("Unesite elemente niza b: ");
  for(i=0;i<n;i++)
    scanf("%d", &b[i]);

  /*
    Niz c ima 2*n elemenata. Prvih n elemenata niza b, i nakon toga n elemenata niza a.
    Elementi iz niza a se nalaze na pozicijama 0,1,2,...n-1, a elementi niza b na pozicijama
    n,n+1,...2*n. Jednim prolaskom kroz petlju na poziciju i u nizu c stavljamo element niza b - b[i],
    a na poziciju n+i element niza a - a[i].
  */
  for(i=0;i<n;i++)
  {
    c[i] = b[i];
    c[n+i] = a[i];
  }

  for(i=0;i<2*n;i++)
    printf("%d ", c[i]);

  printf("\n");
  
  return 0;
}
