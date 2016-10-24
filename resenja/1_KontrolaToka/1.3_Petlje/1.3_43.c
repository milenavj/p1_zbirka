#include <stdio.h>
#include <math.h>
int main(){
        /* Promenljiva i je brojac, promenljiva S cuva izracunatu sumu,
         * promenljiva znak moze bito 1 ili -1 i odredjuje znak
         * trenutnog clana sume, a promenljiva clan je tekuci clan niza. */
	int i, znak;
	float S;
	float x, eps, clan;
	
	printf("Unesite x: ");
	scanf("%f", &x);
	
	printf("Unesite tacnost eps: ");
	scanf("%f", &eps);
    

        S=0;
	clan = 1;
	i=1;
	znak=1;
        
        /* Kako clanovi sume mogu biti negativni, potrebno je posmatrati
         * apsolutnu vrednost clana. */
	while(fabs(clan)>eps)
        {
            S = S + clan;
            
            /* Promena znaka. */
            znak = - znak;
            clan = clan*x / i;
            clan *= znak;
            
            i++;
	}
	
	printf("S=%f\n", S);
	
	return 0;
}
