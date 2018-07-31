#include <stdio.h>

/* Funkcija koja racuna zbir delilaca broja x. */
int zbir_delilaca(int x){
  int i=0;
  
  /* Na pocetku zbir se inicijalizuje na 0. */
  int zbir = 0;
  
  /* Svaki broj izmedju 1 i x koji deli broj x se dodaje u zbir. */
  for(i=1; i<=x; i++){
	if(x % i == 0)
	  zbir += i;
  }
  
  /* Povratna vrednost funkcije je dobijeni zbir. */
  return zbir;
}

int main(){

	int k, i;
	
	/* Ucitava se broj k. */
	printf("Unesite broj k:");
	scanf("%d", &k);
	
	/* Provera korektnosti ulaza. */
	if(k <= 0)
	  printf("Greska: pogresan unos!\n");
	else{
	  
	  /*Za svaki broj od 1 do k se ispisuje zbir delilaca. */
	  for(i=1; i<=k; i++)
		printf("%d ", zbir_delilaca(i));
	  
	  printf("\n");
	}
	
	
	return 0;
}
