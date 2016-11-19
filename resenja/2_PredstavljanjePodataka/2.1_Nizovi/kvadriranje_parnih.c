#include<stdio.h>

#define MAX 100

/* Funkcija koja kvadrira elemente niza koji se nalaze na parnim pozicijama */
void kvadriranje(float a[], int n){
  
  int i;
  
  /* Obilaze se elementi na parnim pozicijama */
  for(i=0; i<n; i+=2){
      /* I kvadriraju se: a[i] = a[i]*a[i] */
	  a[i]*=a[i]; 
  }
  
}

int main(){
  
  int n, i, j;
  float a[MAX];
  
  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if(n <=0 || n>MAX)
  {
	printf("Greska: Nedozvoljena vrednost!\n");
	return 0;
  }
  
  /* Ucitavaju se elementi niza */
  printf("Unesite elemente niza:");
  for(i=0; i<n; i++)
	scanf("%f", &a[i]);
  
  /* Poziva se funkcije */
  kvadriranje(a,n);
 
  /* Ispisuje se elementi novodobijenog niza */
  /* Koriscenje specifikatora %g za stampanje realnih brojeva omogucava ispis broja
    na onoliko decimalnih mesta koliko ima i sam broj */
  for(i=0; i<n; i++){
	printf("%g ", a[i]);
  }
  printf("\n");

  return 0;
}
