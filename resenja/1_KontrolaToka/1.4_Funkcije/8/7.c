/*
	Napisati funkciju int prestupna(int godina) koja za zadatu godinu proverava da li je prestupna. 
	Funkcija treba da vrati 1 ako je godina prestupna ili 0 ako nije. 
	Napisati program koji ucitava dva cela broja g1 i g2 i ispisuje sve godine iz intervala [g1, g2] koje su prestupne.
*/

#include<stdio.h>

/* Funkcija koja proverava da li je godina prestupna */
int prestupna(int godina){
  if((godina %100 != 0 && godina%4 == 0) || godina%400 == 0)
	return 1;
  else
	return 0;
}

/* Funkcija koja proverava da li postoji prestupna godina u datom intervalu */
int postoji_prestupna(int g1, int g2){
  for(; g1<=g2; g1++){
	if(prestupna(g1))
	  return 1;
  }
  return 0;
}

int main(){
  
  int g1, g2;
  
  /* Ucitavamo godine */
  printf("Unesite dve godine: ");
  scanf("%d%d", &g1, &g2);
  
  /* Proveravamo korektnost ulaza */
  if(g1 < 0 || g2 < 0 || g1>g2){
	printf("Greska: pogresan unos!\n");
  }
  else{
	
	/* Proveravamo da li uopste postoji prestupna godina u datom intervalu */
	if(postoji_prestupna(g1,g2)){
	  /* Ako postoje, ispisujemo ih */
	  printf("Prestupne godine su: ");
	  for(; g1<=g2; g1++){
		if(prestupna(g1))
		  printf("%d ", g1);
	  }
	  printf("\n");
	}else{
	  /* U suprotnom, stampamo odgovarajucu poruku */
	  printf("Nema prestupnih godina u ovom intervalu!\n");
	}
  }
  return 0;
}
