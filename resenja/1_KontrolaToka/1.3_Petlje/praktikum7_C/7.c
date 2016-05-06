/* Sa standardnog ulaza se unose realni brojevi sve do unosa broja 0. Napisati program koji izracunava i ispisuje
aritmeticku sredinu unetih brojeva. */

#include <stdio.h>
#include <math.h>

int main(){

	float x; 
	int broj_brojeva;
	float suma;
	
	/* Inicijalizujemo vrednosti */
	broj_brojeva=0;
	suma=0;

	
	printf("Unesite brojeve: ");
	
	/* U petlji */
	while(1){
		/* Ucitavamo broj sa ulaza */
		scanf("%f", &x);
		
		/* Ako je korisnik uneo 0, prekidamo sa petljom */
		if(x==0)
			break;	
			
		/* Inace .. */
		
		/* Procitani broj dodajemo na sumu */
		suma+=x;
		/* I uvecavamo broj procitanih brojeva */
		broj_brojeva++;
	}
	
	/* Ispisujemo trazeni rezultat */
	printf("Aritmeticka sredina: %.4f\n", suma/broj_brojeva);
	
	return 0;	
}



