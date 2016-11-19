#include <stdio.h>

#define MAX 100

int main()
{
  int a[MAX];
  int i, j, n_a;

  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n_a);
  if(n_a<1 || n_a>100)
  {
    printf("Greska: Nedozvoljena vrednost!\n");
    return -1;
  }

  /* Ucitavaju se elementi niza */
  printf("Unesite elemente niza: ");
  for(i=0;i<n_a;i++)
    scanf("%d", &a[i]);

  
  /*
    1. nacin

    int b[MAX], n_b;
    
    // Brojac j predstavlja poziciju u nizu b na koju treba smestiti element niza a. Njegova pocetna vrednost je 0.

  for(i=0, j=0;i<n_a;i++){
    // Ako je tekuci element niza a paran 
    if(a[i]%2 == 0)
    {
      // Smesta se na poziciju j u nizu b
      b[j] = a[i];
      // Vrednost brojaca j se priprema za narednu iteraciju
      j++;
    }
    
    // Ako je element niza a neparan, sa njim nista ne treba raditi
  }

  // Broj elemenata novodobijenog niza b je j
  n_b = j;

  // Ispisuju se elementi niza b
  for(i=0;i<n_b;i++)
    printf("%d ", b[i]);

  */

  /*
   2. nacin

   J predstavlja brojac prve slobodne pozicije na koju se moze upisati element niza koji treba da ostane u nizu.
   Kada se naidje na element koji je paran, on se kopira na mesto a[j] i poveca se vrednost brojaca j.
   Ukoliko se naidje na element koji je neparan, njega treba preskociti.
  */
  for(i=0, j=0;i<n_a;i++)
  {
    /* Ako je tekuci element niza a paran */
    if(a[i]%2 == 0)
    {
      /* Premesta se na poziciju j */
      a[j] = a[i];
      
      /* Vrednost brojaca j se priprema za narednu iteraciju */
      j++;
    }
    
    /* Ako je tekuci element niza a neparan, sa njim nista ne treba raditi */
  }

  /* U nizu a se sada na pozicijama od 0,...,j-1 nalaze elementi koji su parni, te je njegova nova dimenzija j. */
  n_a=j;

  /* Ispisuju se elementi modifikovanog niza a */
  for(i=0;i<n_a;i++){
    printf("%d ", a[i]);
  }
  printf("\n");

  return 0;
}
