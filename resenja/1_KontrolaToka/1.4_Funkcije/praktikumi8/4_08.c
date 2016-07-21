#include <stdio.h>

/* Funkcija koja racuna zbir delilaca broja x */
int zbir_delilaca(int x){
  int i=0;
  
  /* Na pocetku zbir inicijalizujemo na 0 */
  int zbir = 0;
  
  /* Svaki broj izmedju 1 i x koji deli broj x dodajemo u zbir. */
  for(i=1; i<=x; i++){
	if(x % i == 0)
	  zbir += i;
  }
  
  /* Vracamo dobijeni zbir */
  return zbir;
}

int main(){

	int k, i;
	
	/* Ucitavamo broj k */
	printf("Unesite broj k:");
	scanf("%d", &k);
	
	/* Proveravamo korektnost ulaza */
	if(k <= 0)
	  printf("Greska: pogresan unos!\n");
	else{
	  
	  /*Za svaki broj od 1 do k ispisujemo zbir delilaca*/
	  for(i=1; i<=k; i++)
		printf("%d ", zbir_delilaca(i));
	  
	  printf("\n");
	}
	
	
	return 0;
}
