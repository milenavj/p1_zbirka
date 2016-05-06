/* Sa standardnog ulaza se unosi ceo pozitivan broj n, a zatim i n celih brojeva. Napisati program koji ispisuje
broj sa najvecim brojem cifara. Ukoliko ima vise takvih, ispisati prvi. */

#include <stdio.h>
#include <math.h>

int main(){

	int n; 
	int x, x_kopija, br_cifara; 
	int max_br_cifara, broj;
	int i;
	
	/* Citamo vrednost sa ulaza */
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	/* Postavljamo maksimalan broj cifara na 0  - svaki broj ima vise od 0 cifara pa je ova vrednost neutralna */
	max_br_cifara=0;
	
	/* Ucitavamo broj po broj */
	printf("Unesite n brojeva: ");
	for(i=0; i<n; i++){
		scanf("%d", &x);
		
		/* Odredjujemo broj cifara unetog broja x */
		x_kopija=abs(x);
		br_cifara=0;
		while(x_kopija!=0){
			x_kopija=x_kopija/10;
			br_cifara++;
		}
		/* Ako je broj cifara unetog broja veci od maksimalnog */
		if(br_cifara>max_br_cifara){
			/* Cuvamo ga */
			max_br_cifara=br_cifara;
			/* I zbog ispisa rezultata, cuvamo i originalni broj */
			/* Zbog ovoga smo morali i da racunamo broj cifara nad kopijom broja x kako ne bismo promenili njegovu vrednost */
			broj=x;
		}
	}
	
	/* Ispisujemo rezultat */
	printf("%d\n", broj);
	
	return 0;
	
}


