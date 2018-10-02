#include<stdio.h>

/* Funkcija koja proverava da li je godina prestupna. */
int prestupna(int godina){
  if((godina %100 != 0 && godina%4 == 0) || godina%400 == 0)
	return 1;
  else
	return 0;
}

/* Funkcija koja proverava da li postoji prestupna godina u datom intervalu. */
int postoji_prestupna(int g1, int g2){
  for(; g1<=g2; g1++){
	if(prestupna(g1))
	  return 1;
  }
  return 0;
}

int main(){
  
  int g1, g2;
  
  /* Unos dve godine. */
  printf("Unesite dve godine: ");
  scanf("%d%d", &g1, &g2);
  
  /* Proverava se korektnost ulaza. */
  if(g1 < 0 || g2 < 0 || g1>g2){
	printf("Greska: pogresan unos!\n");
  }
  else{
	
	/* Proverava se da li postoji prestupna godina u datom intervalu. */
	if(postoji_prestupna(g1,g2)){
	  /* Ako postoje, prestupne godine se ispisuju. */
	  printf("Prestupne godine su: ");
	  for(; g1<=g2; g1++){
		if(prestupna(g1))
		  printf("%d ", g1);
	  }
	  printf("\n");
	}else{
	  /* A ako ne postoje, stampa se odgovarajuca poruka. */
	  printf("Nema prestupnih godina u ovom intervalu!\n");
	}
  }
  return 0;
}
