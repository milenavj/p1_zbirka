#include<stdio.h>

#define MAX 100

/* Funckija racuna zbir prvih k pozitivnih elemenata niza */
float zbir_pozitivnih(float a[], int n, int k){

  int i;
  
  /* Zbir pozitivnih elemenata */
  float zbir=0;
  
  /* Obilazi se element po element niza - postupk se zavrsava ukoliko se dodje do kraja niza 
    ili ukoliko se sabere k pozitivnih elemenata */
  for(i=0; i<n && k>0; i++){
    /* Ako je tekuci element pozitivan broj */
	if(a[i] >= 0){
	  /* Dodaje se zbiru */
	  zbir+=a[i];
      /* I umanjuje se brojac pozitivnih elemenata */
	  k--;
	}
  }
  
  /* Vraca se izracunata vrednost */ 
  return zbir;
} 

int main(){
  int n, i, k;
  float a[MAX];
  
  /* Ucitava se broj elemenata niza i proverava se njegova ispravnost */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if(n<=0 || n> MAX){
	printf("Greska: Nedozvoljena vrednost!\n");
	return 0;
  }
  
  /* Ucitavaju se elementi niza */
  printf("Unesite elemente niza: ");
  for(i=0; i<n; i++)
	scanf("%f", &a[i]);
  
  /* Ucitava se broj k i proverava se njegova ispravnost */
  printf("Unesite vrednost za k: ");
  scanf("%d", &k);
  if(k<0 || k>n){
	printf("Greska: Nedozvoljena vrednost!");
	return 0;
  }
  
  /* Ispisuje se rezultat poziva funkcije */
  printf("Zbir je: %.2f\n", zbir_pozitivnih(a,n,k));
  
  return 0;
}