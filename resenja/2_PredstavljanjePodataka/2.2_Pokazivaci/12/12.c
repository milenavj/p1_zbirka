/* 
	Napisati funckiju 
		void min_max(float a[], int n, float* min, float* max)
	koja izracunava minimalni i maksimalni element niza a duzine n. 
	Napisati zatim i program koji ucitava niz realnih brojeva maksimalne
	duzine 50 i ispisuje vrednosti minimuma i maksimuma na tri decimale.
	
*/

#include<stdio.h>
#define MAX 50

void min_max(float a[], int n, float* min, float* max){
	
	int i;
	
	/* Inicijalizujemo vrednosti minimuma i maksimuma */
	*min=a[0];
	*max=a[0];
	
	/* Obilazimo preostale elemente niza */
	for(i=1; i<n; i++){

		/* Ako je tekuca vrednost veca od maksimalne, azuriramo maksimum */		
		if(a[i]>*max){
			*max=a[i];
		}
		
		/* Ako je tekuca vrednost manja od minimalne, azuriramo minimum */		
		if(a[i]<*min){
			*min=a[i];
		}
	}
}

int main(){
	int i, n;
	float a[MAX], min, max;

	/* Ucitavamo dimenziju niza */
	printf("Unesite broj elemenata niza: ");
	scanf("%d", &n);
  
	if(n<0 || n>MAX){
		printf("Greska: pogresna dimenzija niza!\n");
		return -1;
	}
  
	/* Ucitavamo elemente niza */
	printf("Unesite elemente niza:\n");
	for(i=0; i<n; i++){
		scanf("%f", &a[i]);
	}
	
	/* Pozivamo funkciju za racunanje maksimuma i minimuma */
	min_max(a, n, &min, &max);	
	
	/* Ispisujemo rezultat */
	printf("Minimum: %.3f\n", min);
	printf("Maksimum: %.3f\n", max);
	
	return 0;
	
}	

