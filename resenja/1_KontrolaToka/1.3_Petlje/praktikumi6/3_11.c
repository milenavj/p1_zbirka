/* Sa standardnog ulaza unose se realan broj x i ceo neoznacen broj n.
Napisati program koji izracunava sumu S=1+1/x+1/x^2+1/x^3+...+1/x^n */

#include <stdio.h>
int main(){
	unsigned n, i;
	float x, S, stepen;
	
	printf("Unesite redom brojeve x i n: ");
	scanf("%f %u", &x, &n);
	
	S=1;	
	stepen=1;
	for(i=1; i<=n; i++){
		stepen=stepen*x;
		S=S+1/stepen;
	}
	
	printf("S=%f\n", S);
	
	return 0;
}
