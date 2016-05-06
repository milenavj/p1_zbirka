/* Sa standardnog ulaza se unose celi pozitivni brojevi n (n > 1) i d, a zatim i n celih brojeva. Napisati program
koji izracunava koliko ima parova uzastopnih brojeva medju unetim brojevima koji se nalaze na rastojanju d.
Rastojanje izmedu brojeva je definisano sa d(x, y) = |y − x|. Rezultat ispisati na standardni izlaz. */

#include <stdio.h>
#include <math.h>

int main(){

	int n; 
	int d; 
	int x, y;
	int broj_parova;
	int i;

	/* Ucitavamo vrednosti sa ulaza */	
	printf("Unesite brojeve n i d: ");
	scanf("%d %d", &n, &d);
	
	/* Inicijalizujemo broj parova */
	broj_parova=0;
	
	printf("Unesite n brojeva: ");

	/* Ucitavamo prvi broj */
	scanf("%d", &x);
	
	for(i=1; i<n; i++){
		/* Ucitavamo naredni broj */
		scanf("%d", &y);
		
		/* Ako su brojevi na rastojanju d */
		if(abs(y-x)==d)
			/* Treba uvecati broj parova */
			broj_parova++;

		/* Cuvamo broj iz tekuce iteracije kako bismo mogli da ga upotrebimo u narednoj iteraciji */
		x=y;		
	}
	
	/* Ispisujemo rezultat */
	printf("Broj parova: %d\n", broj_parova);
	
	return 0;
	
}

