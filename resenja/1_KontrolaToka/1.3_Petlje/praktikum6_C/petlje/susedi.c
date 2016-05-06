/* Sa standardnog ulaza unosi se neoznacen ceo broj. Napisati program koji formira i ispisuje broj koji se dobija
izbacivanjem cifara koje su jednake zbiru svojih suseda. Cifre se posmatraju sa desna na levo. */

#include <stdio.h>

int main(){
	unsigned n, novo_n; 
	int stepen;
	int cifra_levo, cifra_sredina, cifra_desno;
	
	/* Ucitavamo broj sa ulaza */
	printf("Unesite broj: ");
	scanf("%u", &n);
	
	
	/* Stepen broja 10 sa kojim cemo mnoziti cifre izdvojenog broja */	
	stepen=1;
	
	/* Nova vrednost broja */
	novo_n=0;

	/* Sve dok u zapisu broja imamo barem tri cifre  */
	while(n>99){
		/* Izdvajamo srednju cifru, cifru desno od nje i cifru levo od nje: 
		npr. za trojku 583 8 je srednja cifra, 3 je cifra desno, a 5 cifra levo */
		cifra_desno=n%10;
		cifra_sredina=(n/10)%10;
		cifra_levo=(n/100)%10;
		
		/* U novi broj smestamo desnu cifru */
		novo_n+=cifra_desno*stepen;
		
		/* Azuriramo vrednost stepena */
		stepen=stepen*10;
		
		/* Ako je srednja cifra jednaka zbiru leve i desne cifre */
		if(cifra_levo+cifra_desno==cifra_sredina){
		
			/* Treba izbaciti srednju cifru, pa broj n azuriramo tako sto ga podelimo sa 100 */
			n=n/100;	
		}
		else{
		
			/* Inace, zadrzavamo srednju cifru i odbacujemo samo poslednju */
			n=n/10;			
		}
	}
	
	/* Na novi broj dodajemo preostali dvocifreni ili jednocifreni broj */
	novo_n=n*stepen+novo_n;
	
	/* I ispisujemo rezultat */
	printf("%d\n", novo_n);
	
	
	return 0;
	
}

