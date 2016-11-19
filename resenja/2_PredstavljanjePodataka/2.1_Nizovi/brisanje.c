#include <stdio.h>

#define MAX 100

int main()
{

  int a[MAX];
  int n;
  int i,j; 
  char poslednja_cifra;
  int novo_n;

  /* Ucitava se dimenzija niza i proverava njena vrednost */
  printf("Unesite dimenziju niza:\n");
  scanf("%d", &n);
  if (n<1 || n>MAX)
  {
    printf("Pogresna vrednost!\n");
    return -1;
  }
  
  /* Ucitavaju se elementi niza a */
  printf("Unesite elemente niza a:\n");
  for(i=0;i<n;i++)
  {
    scanf("%d", &a[i]);
  }

  
  /* Obilaze se svi elementi niza a */
  for(i=0, j=0; i<n; i++)  
  {
    /* Izdvaja se poslednja cifra tekuceg elementa */
    poslednja_cifra = a[i]%10;
    
    /*
       Ako je poslednja cifra 0 ili je element deljiv svojom poslednjom cifrom, 
       zadrzavamo ga i smestamo na poziciju j
    */
    if (poslednja_cifra==0 || a[i]%poslednja_cifra==0)
    {
        a[j]=a[i];
        j++;
    }
  }
  /*
    Dimenzija novog niza odgovara posledjoj vrednosti brojaca j
  */
  novo_n=j;

  /* Ispisuje se rezultujuci niz */
  printf("Niz a nakon izmena:\n");
  for(i=0; i<novo_n;i++)
    printf("%d ", a[i]);
  printf("\n");

  
  return 0;
}