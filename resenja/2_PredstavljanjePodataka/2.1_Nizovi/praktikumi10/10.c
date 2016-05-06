#include <stdio.h>
#include <math.h>

#define MAX 100

/*
  Funkcija koja proverava da li je broj prost.
  Vraca 1 ukoliko broj jeste prost, inace 0.
  Napomena: Broj 1 cemo tretirati kao prost broj
*/
int prost(int x)
{
  int i;
  
  /* Da bismo pokrili i slucaj negativnih brojeva, radimo sa apsolutnom vrednoscu broja */
  x=abs(x);

  if(x == 1 || x == 2 || x == 3)
    return 1;

  if(x%2 == 0)
    return 0;

  for(i=3;i<=sqrt(x);i+=2)
    if(x%i == 0)
      return 0;

  return 1;
}

int main()
{
  int a[MAX];
  int i, j, n_a, n_b;

  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n_a);

  if(n_a<1 || n_a>MAX)
  {
    printf("Greska: pogresan unos!\n");
    return -1;
  }

  printf("Unesite elemente niza: ");
  for(i=0;i<n_a;i++)
    scanf("%d", &a[i]);

  /*
    1. nacin

    J nam predstavlja brojac prve slobodne pozicije na koju mozemo upisati element niza koji treba da ostane u nizu.
    Kada naletimo na element koji nije prost, kopiramo ga na mesto a[j] i povecamo brojac j.
    Ukoliko naletimo na element koji je prost, njega samo preskocimo.

  */

  for(i=0, j=0;i<n_a;i++)
  {
    if(prost(a[i]) == 0)
    {
      a[j] = a[i];
      j++;
    }
  }

  n_a=j;

  for(i=0;i<n_a;i++)
    printf("%d ", a[i]);

  printf("\n");
  
  /*
    2. nacin

	int b[MAX];
    Prolazimo kroz niz a i svaki broj koji nije prost kopiramo u niz b i povecamo j - brojac elemenata u nizu b.  

  for(i=0, j=0;i<n_a;i++)
    if(prost(a[i]) == 0)
    {
      b[j] = a[i];
      j++;
    }

  n_b = j;

  for(i=0;i<n_b;i++)
    printf("%d ", b[i]);
  */
  return 0;
}
