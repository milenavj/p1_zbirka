#include <stdio.h>

int main()
{
	
	unsigned poletanje, poletanje_sat, poletanje_minut;
	unsigned sletanje, sletanje_sat, sletanje_minut;
	unsigned duzina, duzina_sat, duzina_minut;
	
	printf("Unesite vreme poletanja: ");
	scanf("%u%u", &poletanje_sat, &poletanje_minut);
	

	printf("Unesite vreme sletanja: ");
	scanf("%u%u", &sletanje_sat, &sletanje_minut);
	
	/* Pretvoricemo i vreme poletanja i vreme sletanja u sekunde */ 
        poletanje=poletanje_sat*3600+poletanje_minut*60;
        sletanje=sletanje_sat*3600 + sletanje_minut*60;
   
        /* I izracunati razliku u sekundama */
	duzina=sletanje-poletanje;
	
        /* Izdvajamo broj sati i broj minuta. */
	duzina_sat=duzina/3600;
	duzina_minut=(duzina%3600)/60;
	
	
        /* I ispisujemo rezultat */
	printf("Duzina trajanja leta je %u h i %u min\n", duzina_sat, duzina_minut);
	
	
	return 0;
}
