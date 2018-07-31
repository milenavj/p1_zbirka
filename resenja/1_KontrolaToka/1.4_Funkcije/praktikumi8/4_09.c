#include <stdio.h>

/* Funkcija koja uklanja broj stotina iz broja n. */
int ukloni_stotine(int n){
  
  /* Broj izmedju -100 i 100 nema cifru stotina, pa se vraca taj isti broj. */
  if(n>-100 && n<100)
	return n;
  else
  {
	/* U suprotnom se vraca broj sa uklonjenom cifrom stotina. */

	/* Odredjivanje znaka broja. */
	int znak=(n<0)? -1 : 1;
	
	/* Da bi se izbegle greske menja se apsolutna vrednost broja, a znak se naknadno dodaje pomocu mnozenja. */
	n=abs(n);

	return znak*((n/1000)*100 + n%100);
  }
}

/* Funkcija koja vraca znak broja. */
int znak(int broj){
  return broj<0?-1:1;
}

int main(){

  int broj;
  
  while(1){
	
	/* Unos broja. */
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	/* Broj 0 oznacava kraj unosa. */
	if(broj == 0)
	  break;
	
	/* Poziv funkcije i ispis rezultata. */
	printf("%d\n", znak(broj)*ukloni_stotine(abs(broj)));
  }
  
  
  return 0;
}
