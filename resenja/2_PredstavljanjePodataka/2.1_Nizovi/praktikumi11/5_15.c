/*
  Napisati funkciju float zbir_pozitivnih(float a[], int n, int k) koja izracunava zbir prvih k pozitivnih elemenata realnog niza a duzine n. 
  Napisati i program koji testira rad funkcije. Pretpostaviti da duzina niza nece biti veca od 100.
 */

#include<stdio.h>
#define MAX 100

/*Funckija racuna zbir prvih k pozitivnih clanova niza a*/
float zbir_pozitivnih(float a[], int n, int k){
  int i;
  
  /*Na pocetku inicijalizujemo sumu na 0*/
  float s=0;
  
  /*Prolazimo kroz niz brojeva i zaustavljamo se ili ako smo dosli do kraja ili ukoliko smo sabrali k brojeva */
  for(i=0; i<n && k>0; i++){
	if(a[i] >= 0){
	  /*Kada naidjemo na pozitivan element, uvecavamo sumu i smanjujemo k*/
	  s+=a[i];
	  k--;
	}
  }
  
  /*Na kraju vracamo izracunatu sumu */
  return s;
} 

int main(){
  int n, i, k;
  float a[MAX];
  
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  
  /*Proveravamo korektnost ulaza*/
  if(n<=0 || n> MAX){
	printf("Greska: pogresan unos!\n");
	return 0;
  }
  
  /*Ucitavamo elemente niza*/
  printf("Unesite elemente niza: ");
  for(i=0; i<n; i++)
	scanf("%f", &a[i]);
  
  /*Ucitavamo k*/
  printf("Unesite vrednost za k: ");
  scanf("%d", &k);
  
  /*Proveravamo korektnost za k*/
  if(k<0){
	printf("Greska: pogresan unos!");
	return 0;
  }
  
  /*Ispisujemo rezultat*/
  printf("Zbir je: %.2f\n", zbir_pozitivnih(a,n,k));
  return 0;
}