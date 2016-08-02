/* Sa standradnog ulaza unose se realan broj x i ceo neoznacen broj n. Napisati
program koji izracunava x^n */

#include <stdio.h>

int main(){

	int n;
	float x;
	float vrednost;
	unsigned exp;
	
	/* Ucitavaju se brojevi x i n */
	printf("Unesite redom brojeve x i n: ");
	scanf("%f %d", &x, &n );

    /* Pocetna vrednost stepena koji se racuna  */
	vrednost=1;

	for(exp=1; exp<=n; exp++)
		vrednost=vrednost*x;
		
	/* Stampamo rezultat */
	printf("%f\n",vrednost);
	
	return 0;
}