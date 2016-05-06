/* Sa standardnog ulaza se unosi ceo pozitivan broj n, a zatim i n celih brojeva. Napisati program koji ispisuje
broj sa najvecom cifrom desetica. Ukoliko ima vise takvih, ispisati prvi. */

#include <stdio.h>
#include <math.h>

int main(){

	int n; 
	int x, x_desetica; 
	int max_desetica, broj;
	int i;
	
	/* Citamo vrednost sa ulaza */
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	/* Postavljamo maksimalnu cifru desetice na 0 - 0 je svakako najmanja cifra pa je pocetna vrednost neutralna  tj. 
	ne moze da utice na maksimum koji izracunavamo. Nije uvek zgodno pretpostaviti da je maksimalna vrednost 0. Na primer, 
	ako trazimo maksimum celih brojeva, a korisnik unese -32 -7 i -22, maksimalni je broj -7 */
	max_desetica=0;
	
	/* Ucitavamo broj po broj */
	printf("Unesite n brojeva: ");
	for(i=0; i<n; i++){
		scanf("%d", &x);
		
		/* Izdvajamo cifru desetica procitanog broja */
		x_desetica=(abs(x)/10)%10;
		
		/* Ako je ona veca od maksimalne cifre desetica */
		if(x_desetica>max_desetica){
			/* Cuvamo je */
			max_desetica=x_desetica;
			/* Ali zbog ispisa, cuvamo i broj u kojem se ona pojavljuje */
			broj=x;
		}
	}
	
	/* Ispisujemo rezultat */
	printf("%d\n", broj);
	
	return 0;
	
}

