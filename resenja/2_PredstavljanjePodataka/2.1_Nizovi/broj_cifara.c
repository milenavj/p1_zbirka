#include <stdio.h>
#include <ctype.h>

#define MAX 100

/* Funkcija prebrojava cifre u datom nizu karaktera */
int cifre(char a[], int n)
{
  int i;
  
  /* Brojac cifara */
  int broj_cifara = 0;
 
  /* Obilazi se element po element niza */
  for(i=0;i<n;i++){
    /* Ako je tekuci element cifra */
    if(isdigit(a[i])){
      /* Uvecava se broj cifara */
      broj_cifara++;
    }
  }

  /* Vraca se izracunata vrednost */
  return broj_cifara;
}

int main()
{
  char a[MAX];
  int n;
  int i;
  
  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost */
  printf("Unesite broj elemenata niza:");
  scanf("%d", &n);
  if(n<=0 || n>MAX)
  {
     printf("Greska: Nedozvoljena vrednost!\n");
     return 0;
  }
  
  /* Ucitavaju se elementi niza */
  printf("Unesite elemente niza:");
  for(i=0;i<n;i++) {
    /* Preskace se prethodno uneti znak za novi red */
   getchar();
   
   /* A zatim se ucitava sam karakter i smesta u niz */
   scanf("%c",&a[i]);
  } 
  
  /* Ispisuje se rezultat poziva funkcije */
  printf("Broj cifara je: %d\n", cifre(a,n));
  
  return 0;
}
