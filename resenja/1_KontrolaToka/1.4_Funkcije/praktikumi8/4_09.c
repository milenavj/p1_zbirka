#include <stdio.h>

/* Funkcija koja uklanja broj stotina iz broja n */
int ukloni_stotine(int n){
  
  /* Ako je broj izmedju -100 i 100 nema cifru desetica pa onda vracamo isti taj broj */
  if(n>-100 && n<100)
	return n;
  else
  {
	/* U suprotnom vracamo broj sa uklonjenom cifrom stotina */

	/* Odredjujemo znak broja */
	int znak=(n<0)? -1 : 1;
	
	/* I nadalje radimo sa apsolutnom vrednoscu broja */
	n=abs(n);

	return znak*((n/1000)*100 + n%100);
  }
}

/* Funkcija koja vraca znak broja */
int znak(int broj){
  return broj<0?-1:1;
}

int main(){

  int broj;
  
  while(1){
	
	/* Ucitavamo broj sa standardnog ulaza */
	printf("Unesite broj: ");
	scanf("%d", &broj);
	
	/* Broj 0 oznacava kraj rada */
	if(broj == 0)
	  break;
	
	/* Ispisujemo rezultat, vodeci racuna da program treba da radi ispravno i za negativne brojeve */
	printf("%d\n", znak(broj)*ukloni_stotine(abs(broj)));
  }
  
  
  return 0;
}
