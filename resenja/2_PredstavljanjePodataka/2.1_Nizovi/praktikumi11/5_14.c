/*
 Napisati funkciju int zbir(int a[], int n, int i, int j) koja racuna zbir elemenata niza celih brojeva a duzine n od pozicije i do pozicije j. 
 Napisati i program koji testira rad funkcije. Pretpostaviti da duzina niza nece biti veca od 100.

 */

#include<stdio.h>
#define MAX 100

/*Funkcija koja vraca zbir elemenata koji se nalaze izmedju pozicija i i j*/
int zbir(int a[], int n, int i, int j){
  /*Na pocetku incijalizujemo sumu na 0*/
  int k, s=0;
  
  /*Krecemo od pozicije i i idemo do pozicije j i dodajemo na sumu tekuci element niza*/
  for(k=i; k<=j; k++)
	s+=a[k];
  
  /*Na kraju vracamo izracunatu sumu*/
  return s;
}

int main(){
  
  int n, i, j;
  int a[MAX];
  
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  
  /*Proveravamo korektnost ulaza*/
  if(n <=0 || n>100)
  {
	printf("Greska: pogresan unos!\n");
	return 0;
  }
  
  /*Ucitavamo elemente niza*/
  printf("Unesite elemente niza:");
  for(i=0; i<n; i++)
	scanf("%d", &a[i]);
  
  /*Ucitavamo interval [i,j]*/
  printf("Unesite vrednosti za i i j: ");
  scanf("%d%d", &i, &j);
  
  /*Proveravamo korektnost zadatog intervala */
  if(i > n-1 || j > n-1 || i > j){
	printf("Greska: nekorektne vrednosti granica!\n");
	return 0;
  }
  
  /*Ispisujemo rezultat*/
  printf("Zbir je: %d", zbir(a,n,i,j));
  
  return 0;
}