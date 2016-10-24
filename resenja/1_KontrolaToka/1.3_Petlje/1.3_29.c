#include <stdio.h>

int main(){
	int n, novo_n; 
	int stepen;
	int cifra_levo, cifra_sredina, cifra_desno;
	
	/* Ucitavanje broja. */
	printf("Unesite broj: ");
	scanf("%d", &n);
	
	if (n <= 0)
	{
	  printf("Neispravan unos.\n");
	  return -1;
	}
	
	/* Stepen broja 10 sa kojim se mnoze cifre izdvojenog broja. */	
	stepen=1;
	
	/* Nova vrednost broja. */
	novo_n=0;

	/* Provera da li u zapisu broja postoje barem tri cifre.  */
	while(n>99){
		/* Izdvaja se srednja cifra, cifra desno od nje i cifra 
		 * levo od nje: npr. za trojku 583 8 je srednja cifra, 
		 * 3 je cifra desno, a 5 cifra levo. 
		 */
		cifra_desno=n%10;
		cifra_sredina=(n/10)%10;
		cifra_levo=(n/100)%10;
		
		/* U novi broj se smesta desna cifra. */
		novo_n+=cifra_desno*stepen;
		
		/* Azurira se vrednost stepena. */
		stepen=stepen*10;
		
		/* Provera da li je srednja cifra jednaka zbiru leve i 
		 * desne cifre.
		 */
		if(cifra_levo+cifra_desno==cifra_sredina){
		
			/* Treba izbaciti srednju cifru, pa broj n se azurira 
			 * tako sto se podeli sa 100. 
			 */
			n=n/100;	
		}
		else{
		
			/* Inace, zadrzava se srednja cifra i odbacuje 
			 * se samo poslednja. 
			 */
			n=n/10;			
		}
	}
	
	/* Na novi broj se dodaje preostali dvocifreni 
	 * ili jednocifreni broj. 
	 */
	novo_n=n*stepen+novo_n;
	
	/* Ispisivanje rezultata. */
	printf("%d\n", novo_n);
	
	
	return 0;
	
}

