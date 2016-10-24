#include <stdio.h>
#include <math.h>

int main(){

	int x; 
	int min, max;
	
	printf("Unesite brojeve: ");

	/* Prvi broj se ucitava izvan petlje zbog 
         * inicijalizacije maksimuma i minimuma. */	
	scanf("%d", &x);
	max=x;
	min=x;
	
	/* Sve dok se ne unese 0, ucitavaju se brojevi u petlji. */
	while(x!=0){	
	
		/* Provera da li je procitani broj veci od aktuelnog maksimuma. */
		if(x>max)
			max=x;
		/* Provera da li je procitani broj manji od aktuelnog minimuma. */			
		if(x<min)
			min=x;
			
		/* Ucitavanje narednog broja. */
		scanf("%d", &x);
	}
	

	printf("Razlika: %d\n", max-min);
	
	return 0;	
}


