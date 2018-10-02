#include <stdio.h>

#define MAX 100

/* Funkcija vraca broj parnih elemenata niza koji prethode maksimalnom elementu niza. */
int prebrojavanje(int a[], int n)
{
  int i;
  
  int maksimum;
  int pozicija_maksimuma;
  
  /* Brojac elemenata koji su parni i prethode maksimalnom. */
  int broj_parnih;

  /* Pronalazi se maksimalni element niza i njegova pozicija. */
  maksimum = a[0];
  pozicija_maksimuma = 0;

  for(i=1;i<n-1;i++)
    if(a[i]> maksimum)
    {
      maksimum = a[i];
      pozicija_maksimuma = i;
    }

  /* Prebrojavaju se parni elementi koji prethode maksimalnom. */
  broj_parnih = 0;
  for(i=0; i < pozicija_maksimuma; i++){
    if(a[i]%2==0){
      broj_parnih++;
    }
  }

  /* Vraca se izracunata vrednost. */
  return broj_parnih;
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
  for(i=0;i<n;i++){ 
   scanf("%d",&a[i]);
  }
   
  /* Ispisuje se rezultat poziva funkcije. */
  printf("%d\n", prebrojavanje(a,n));
  
  return 0;
}
