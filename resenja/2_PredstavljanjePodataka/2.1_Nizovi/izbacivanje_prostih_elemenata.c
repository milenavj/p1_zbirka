#include <stdio.h>
#include <math.h>

#define MAX 100

/*
  Funkcija koja proverava da li je zadati broj prost broj.
  Povratna vrednost funkcije je 1 ukoliko broj jeste prost, inace je 0.
*/
int prost(int x)
{
  int i;
  
  /* Posmatra se apsolutna vrednost broja kako bi se pokrio i slucaj negativnih brojeva */
  x=abs(x);

  /* Brojevi 1, 2 i 3 su prosti */
  if(x == 2 || x == 3)
    return 1;

  /* Ako je broj paran nije prost */
  if(x%2 == 0)
    return 0;

  /* Ako broj ima delioce u skupu [3, koren_broja(x)] takodje nije prost */
  for(i=3;i<=sqrt(x);i+=2){
    if(x%i == 0)
      return 0;
  }

  /* Ako su svi uslovi ispunjeni, broj je prost */
  return 1;
}

int main()
{
  int a[MAX];
  int i, j, n_a, n_b;

  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n_a);
  if(n_a<1 || n_a>MAX)
  {
    printf("Greska: Nedozvoljena vrednost!\n");
    return -1;
  }

  /* Ucitavaju se elementi niza a */
  printf("Unesite elemente niza: ");
  for(i=0;i<n_a;i++)
    scanf("%d", &a[i]);

  
  /*
  1. nacin

  int b[MAX];
   
  
  for(i=0, j=0;i<n_a;i++){
    if(prost(a[i]) == 0)
    {
      b[j] = a[i];
      j++;
    }
  }

  // Broj elemenata novodobijenog niza b je j
  n_b = j;
  
  // Ispisuju se elementi niza b
  for(i=0;i<n_b;i++)
    printf("%d ", b[i]);
  printf("\n");
  
  */

  /*
    2. nacin
  */

  for(i=0, j=0; i<n_a; i++)
  {
    if(prost(a[i]) == 0)
    {
      a[j] = a[i];
      j++;
    }
  }

  n_a = j;

  /* Ispisuju se elementi modifikovanog niza a */
  for(i=0;i<n_a;i++)
    printf("%d ", a[i]);
  printf("\n");
  
  return 0;
}
