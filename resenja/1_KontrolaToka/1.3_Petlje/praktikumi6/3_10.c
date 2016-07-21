/* Sa standardnog ulaza unose se realan broj x i ceo neoznacen broj n. Napisati
program koji izracunava sumu S=x+2*x^2+3*x^3+...+n*x^n */

#include <stdio.h>

int main(){
	unsigned n, i;
	float x, S, stepen;
	
	printf("Unesite redom brojeve x i n: ");
	scanf("%f %u", &x, &n);
	
    /* Inicijalizujemo sumu koju racunamo */
	S=0;	
	
    /* Stepen promenljiva ce sadrzati vrednosti stepena x^n - 
     * pocetna vrednost joj je 1 */
	stepen=1;
    
	for(i=1; i<=n; i++){
		stepen=stepen*x;
		S=S+i*stepen;
	}
	
	printf("S=%f\n", S);
	
	return 0;
}
