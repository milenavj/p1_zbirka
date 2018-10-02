#include<stdio.h>

#define MAX 100

/* Funkcija koja kvadrira elemente niza koji se nalaze na parnim pozicijama. */
void kvadriranje(float a[], int n){
  
  int i;
  
  /* Obilaze se elementi na parnim pozicijama i kvadriraju se: a[i] = a[i]*a[i]. */
  for(i=0; i<n; i+=2)
	  a[i]*=a[i]; 
}

int main(){
  
  int n, i, j;
  float a[MAX];
  
  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if(n <=0 || n>MAX)
  {
	printf("Greska: Nedozvoljena vrednost!\n");
	return 0;
  }
  
  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:");
  for(i=0; i<n; i++)
	scanf("%f", &a[i]);
  
  /* Poziva se funkcija. */
  kvadriranje(a,n);
 
  /* Ispisuju se elementi novodobijenog niza. */
  for(i=0; i<n; i++)
	printf("%g ", a[i]);
  printf("\n");

  return 0;
}
