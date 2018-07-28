#include <stdio.h>

#define MAX 100

/* Funkcija prebrojavanje vraca broj elemenata niza koji su manji od poslednjeg elementa. */
int prebrojavanje(int a[], int n)
{
  int i;
  
  /* Brojac elemenata koji su manji od poslednjeg. */
  int broj_manjih=0;
  
  /* Obilazi se element po element niza, */
  for(i=0;i<n-1;i++){   
    /* Ako je tekuci element manji od poslednjeg (on se nalazi na poziciji n-1) uvecava se brojac. */
    if(a[i]<a[n-1])
      broj_manjih++;
  }
     
  /* Vraca se izracunata vrednost. */   
  return broj_manjih;
}

int main()
{
  int a[MAX];
  int n;
  int i;
 
  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost. */
  printf("Unesite broj elemenata niza:");
  scanf("%d", &n);
  if(n<=0 || n>MAX)
  {
     printf("Greska: Nedozvoljena vrednost!\n");
     return 0;
  }
  
  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:");
  for(i=0;i<n;i++)  
   scanf("%d",&a[i]);
   
  /* Ispisuje se rezultat poziva funkcije. */
  printf("%d\n", prebrojavanje(a,n));
  
  return 0;
}
