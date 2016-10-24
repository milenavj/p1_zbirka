#include <stdio.h>
#include <math.h>

int main(){

	int x; 
	int broj_brojeva;
	int suma;
	
	broj_brojeva=0;
	suma=0;

	
	printf("Unesite brojeve: ");
	
	while(1){
		/* Ucitavanje broja. */
		scanf("%d", &x);
		
		/* Ako je unesena 0, prekida se petlja. */
		if(x==0)
			break;	
			
				
		/* Procitani broj dodaje se na sumu. */
		suma+=x;
		
		/* I uvecava se broj ucitanih brojeva. */
		broj_brojeva++;
	}

	if (broj_brojeva == 0)
	  printf("Nisu uneseni brojevi.\n");
	else
	  /* Prilikom deljenja celih brojeva kao rezultat se dobija ceo broj.
	   * Kako je aritmeticka sredina realan broj, potrebno je izvrsiti
	   * konverziju prilikom deljenja da bi se dobio ispravan rezultat.
	   */
	  printf("Aritmeticka sredina: %.4f\n", (double)suma/broj_brojeva);
	
	return 0;	
}



