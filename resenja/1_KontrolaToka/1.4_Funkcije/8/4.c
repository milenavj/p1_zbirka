/* 
	Napisati funkciju void romb(int n) koja iscrtava romb cija je stranica duzine n. 
	Napisati program koji ucitava ceo pozitivan broj i ispisuje rezultat poziva funkcije. 
	U slucaju pogresnog unosa, ispisati poruku o gresci.
*/
#include<stdio.h>

/* Funkcija koja iscrtava romb */
void romb(int n){
  int i, j;
  
  /* U svakoj liniji */
  for(i=0; i<n; i++){
  
	/* Prvo ispisujemo n-i-1 razmaka */
	for(j=0; j<n-i-1; j++)
	  printf(" ");
	
	/* Zatim ispisujemo n zvezdica */
	for(j=0; j<n; j++)
	  printf("*");
	
	/* Na kraju svake linije stoji oznaka za novi red */
	printf("\n");
  }
  
}

int main(){
  int n;
  
  /* Ucitavamo broj n */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  
  /* Proveravamo korektnost ulaza i ispisujemo rezultat */
  if(n<=0)
	printf("Greska: pogresna dimenzija!\n");
  else
	romb(n);
  
  return 0;
}
