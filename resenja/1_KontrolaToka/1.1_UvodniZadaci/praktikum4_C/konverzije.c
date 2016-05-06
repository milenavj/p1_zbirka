/* Napisati program koji:
1) unetu duzinu u miljama konvertuje u kilometre (1 mi = 1.609344 km)
2) unetu tezinu u funtama konvertuje u kilograme ( 1 lb = 0.45359237 kg)
3) unetu temperaturu u celzijusima konvertuje u farenhajte (F =9·C/5 + 32)
*/

 #include <stdio.h>


int main(){
	float milje;
	float kilometri;
	
	printf("Unesite duzinu u miljama: ");
	scanf("%f", &milje);
	kilometri=milje*1.609344;
	printf("Vrednost duzine u kilometrima je: %f\n", kilometri);
	
	
	float funte;
	float kilogrami;
	
	printf("Unesite tezinu u funtama: ");
	scanf("%f", &funte);
	kilogrami=funte*0.45359237;
	printf("Vrednost tezine u kilogramima je: %f\n", kilogrami);
	
	float celzjusi;
	float farenhajti;
	
	printf("Unesite temperaturu u celzjusima: ");
	scanf("%f", &celzjusi);
	farenhajti=9*celzjusi/5+32;
	printf("Vrednost temperature u farenhajtima je: %f\n", farenhajti);
	
	return 0;
}
