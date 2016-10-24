#include <stdio.h>
#include <stdlib.h>

int main(){

	int n; 
	int d; 
        /* Uzastopni brojevi za koje se racuna rastojanje. */
	int x, y;
	int broj_parova;
	int i;


	printf("Unesite brojeve n i d: ");
	scanf("%d %d", &n, &d);
        
        if (n < 0 || d < 0)
        {
            printf("Neispravan unos.\n");
            return -1;
        }
	
	broj_parova=0;
	
	printf("Unesite n brojeva: ");

	/* Prvi broj se ucitava pre petlje. */
	scanf("%d", &x);
	
	for(i=1; i<n; i++){
		scanf("%d", &y);
		
		/* Provera da li su brojevi na rastojanju d. */
		if(abs(y-x)==d)
			broj_parova++;

		/* Broj iz tekuce iteracije se cuva kako bi
                 * mogao da se upotrebljava u narednoj iteraciji. */
		x=y;		
	}
	
	printf("Broj parova: %d\n", broj_parova);
	
	return 0;
	
}

