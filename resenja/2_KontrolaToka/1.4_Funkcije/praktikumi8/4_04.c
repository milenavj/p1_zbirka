#include<stdio.h>

/* Funkcija koja iscrtava romb. */
void romb(int n){
  int i, j;
  
  /* Petlja iscrtava liniju po liniju romba. */
  for(i=0; i<n; i++){
  
	/* U svakoj liniji prvo se ispisuje n-i-1 razmaka. */
	for(j=0; j<n-i-1; j++)
	  printf(" ");
	
	/* A zatim se ispisuje n zvezdica. */
	for(j=0; j<n; j++)
	  printf("*");
	
	/* Na kraju svake linije stoji oznaka za novi red. */
	printf("\n");
  }
  
}

int main() {
  int n;
  
  /* Ucitavanje velicina romba. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  
  /* Proverava se korektnost ulaza i poziva funkcija za iscrtavanje romba. */
  if(n<=0)
	printf("Greska: pogresna dimenzija!\n");
  else
	romb(n);
  
  return 0;
}
