#include <stdio.h>
#include <math.h>

int main(){

	float x; 
	int broj_brojeva;
	float suma;
	
	broj_brojeva=0;
	suma=0;

	
	printf("Unesite brojeve: ");
	
	while(1){
		/* Ucitavanje broja. */
		scanf("%f", &x);
		
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
	  printf("Aritmeticka sredina: %.4f\n", suma/broj_brojeva);
	
	return 0;	
}



