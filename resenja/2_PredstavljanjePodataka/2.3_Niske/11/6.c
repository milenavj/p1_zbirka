/*
  Napisati funkciju void kvadriranje(float a[], int n) koja kvadrira elemente realnog niza a duzine n koji se nalaze na parnim pozicijama. 
  Napisati i program koji testira rad funkcije. Pretpostaviti da duzina niza ne ́ce biti veca od 100.

 */

#include<stdio.h>
#define MAX 100

/*Funkcija kvadiraj menja niz a tako sto kvadrira sve elemente na parnim pozicijama. */
void kvadriraj(float a[], int n){
  int i;
  
  /*Petljom prolazimo kroz parne pozicije niza i kvadriramo elemente */
  for(i=0; i<n; i+=2){
	  a[i]*=a[i]; //skraceno od a[i] = a[i]*a[i]
  }
  
}

int main(){
  
  int n, i, j;
  float a[MAX];
  
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
    
  /*Proveravamo korektnost ulaza*/
  if(n <=0 || n>MAX)
  {
	printf("Greska: pogresan unos!\n");
	return 0;
  }
  
  /*Ucitavamo elemente niza*/
  printf("Unesite elemente niza:");
  for(i=0; i<n; i++)
	scanf("%f", &a[i]);
  
  /*Pozivamo funkciju koja kvadrira odgovarajuce elemente*/
  kvadriraj(a,n);
  
  /*Stampamo rezultat
   NAPOMENA: Kada koristimo %g za stampanje realnih brojeva,
   oni ce biti istampani na najoptimalniji nacin 
   (imace onoliko decimalnih mesta koliko ima i sam broj)
   */
  for(i=0; i<n; i++)
	printf("%g ", a[i]);
  printf("\n");
   
  return 0;
}
