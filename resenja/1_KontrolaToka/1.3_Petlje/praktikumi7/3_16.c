#include <stdio.h>
#include <stdlib.h>

int main(){

	int n; 
	int x, x_desetica; 
	int max_desetica, broj;
	int i;

	printf("Unesite broj n: ");
	scanf("%d", &n);
        
        if (n < 0)
        {
            printf("Neispravan unos.\n");
            return -1;
        }
        
        if (n == 0)
        {
            printf("Nisu uneseni brojevi.\n");
            return 0;
        }
	
	/* Maksimalna cifra desetice se postavlja na na 0 jer 
         * 0 je svakako najmanja cifra pa je pocetna vrednost neutralna  tj. 
         * ne moze da utice na izracunavanje maksimuma. Ipak, treba biti pazljiv
         * jer nije uvek zgodno pretpostaviti da je maksimalna vrednost 0. 
         * Na primer, ako je zadatak naci maksimum celih brojeva, a korisnik 
         * unese -32 -7 i -22, maksimalni je broj -7, sto je manje od 0.
         */
	max_desetica=0;

	printf("Unesite brojeve: ");
	for(i=0; i<n; i++){
		scanf("%d", &x);
		
		/* Izdvajanje cifre desetica procitanog broja. */
		x_desetica=(abs(x)/10)%10;
		
		/* Proverava da li je izdvojena cifra veca od
                 * trenutne maksimalne cifre desetica. */
		if(x_desetica>max_desetica)
                {
			/* Ako jeste vece, pamti se nova najveca cifra,
                         * kao i broj u kom se pojavila. */
			max_desetica=x_desetica;
			broj=x;
		}
	}
	
	printf("Broj sa najvecom cifrom desetica je %d\n", broj);
	
	return 0;
	
}

