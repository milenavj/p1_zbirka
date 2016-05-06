/* Sa standardnog ulaza unosi se ceo pozitivan broj n, a potom i n celih
brojeva. Izracunati i ispisati zbir onih brojeva koji su neparni i negativni. */

#include <stdio.h>

int main(){
	int n, i, x;
	int zbir=0;

	printf("Unesite broj n: ");
	scanf("%d", &n);
	
    printf("Unesite n brojeva: ");
    
    /* Inicijalizujemo brojac kojim kontrolisemo broj ucitavanja - 
     * treba da ih bude tacno n 
     */
	i=0;
	while(i<n){
        /* Ucitavamo broj */
		scanf("%d", &x); 
		
		/* Proveravamo da li broj negativan i neparan */
		if(x<0 && x%2!=0){
            /* Ako jeste, dodajemo ga na zbir */
			zbir=zbir+x;
		}
		
		/* Uvecavamo brojac iteracija */
		i++;	
	}
	
	/* Ispisujemo rezultat */
	printf("%d\n", zbir);
	
	return 0;
}
