#include <stdio.h>

#define MAX 100

int main()
{
  int a[MAX];
  int i, j, n_a;

  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n_a);

  if(n_a<1 || n_a>100)
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
   Kada naletimo na element koji je paran, kopiramo ga na mesto a[j] i povecamo brojac j.
   Ukoliko naletimo na element koji je neparan, njega samo preskocimo.
  */

  for(i=0, j=0;i<n_a;i++)
  {
    if(a[i]%2 == 0)
    {
      a[j] = a[i];
      j++;
    }
  }

  /*
    Na pozicijama od 0...j-1 se sada nalaze elementi koji su parni, te je nova dimenzija niza sada j.
  */
  n_a=j;

  for(i=0;i<n_a;i++)
    printf("%d ", a[i]);
    
  printf("\n");

  /*
    2. nacin

	int b[MAX], n_b;
	
    Kada naletimo na element niza koji je paran, kopiramo ga u niz b i povecamo j - brojac elemenata niza b.

  for(i=0, j=0;i<n_a;i++)
    if(a[i]%2 == 0)
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
