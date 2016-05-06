/* Sa standardnog ulaza se unose celi brojevi sve do unosa broja 0. Napisati program koji izracunava i ispisuje
razliku najveceg i najmanjeg unetog broja. */

#include <stdio.h>
#include <math.h>

int main(){

	int x; 
	int min, max;
	
	printf("Unesite brojeve: ");

	/* Prvi broj ucitavamo izvan petlje zbog inicijalizacije maksimuma i minimuma */	
	scanf("%d", &x);
	max=x;
	min=x;
	
	/* U petlji smo sve dok ne procitamo broj 0 */
	while(x!=0){	
	
		/* Proveravamo da li je procitani broj veci od aktuelnog maksimuma */
		if(x>max)
			max=x;
		/* Proveravamo da li je procitani broj manji od aktuelnog minimuma */			
		if(x<min)
			min=x;
			
		/* Ucitavamo naredni broj */
		scanf("%d", &x);
	}
	
	/* Ispisujemo razliku najveceg i najmanjeg broja */
	printf("Razlika: %d\n", max-min);
	
	return 0;	
}


