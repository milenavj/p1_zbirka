/* Napisati program koji ucitava sa standardnog ulaza vreme poletanja i vreme
sletanja aviona, a potom ispisuje duzinu trajanja leta. Mozemo pretpostaviti da
su poletanje i sletanje u istom danu. */

#include <stdio.h>

int main(){
	
	int poletanje, poletanje_sat, poletanje_minut, poletanje_sekund;
	int sletanje, sletanje_sat, sletanje_minut, sletanje_sekund;
	int duzina, duzina_sat, duzina_minut, duzina_sekund;
	
	printf("Unesite vreme poletanja: ");
	scanf("%d %d %d", &poletanje_sat, &poletanje_minut, &poletanje_sekund);
	

	printf("Unesite vreme sletanja: ");
	scanf("%d %d %d", &sletanje_sat, &sletanje_minut, &sletanje_sekund);
	
	/* Pretvoricemo i vreme poletanja i vreme sletanja u sekunde */ 
    poletanje=poletanje_sat*3600+poletanje_minut*60+poletanje_sekund;
    sletanje=sletanje_sat*3600 + sletanje_minut*60 +sletanje_sekund;
   
    /* I izracunati razliku u sekundama */
	duzina=sletanje-poletanje;
	
    /* Izdvajamo broj sati, broj minuta i broj sekundi */
	duzina_sat=duzina/3600;
	duzina_minut=(duzina%3600)/60;
	duzina_sekund=(duzina%3600)%60;
	
	
    /* I ispisujemo rezultat */
	printf("Duzina trajanja leta je: %d h %d min %d sec\n", duzina_sat, duzina_minut, duzina_sekund);
	
	
	return 0;
}
