#include <stdio.h>
#include <stdlib.h>

/* Maksimalan broj dana u mesecu je 31, ali dani pocinju od 1, pa je potrebno odvojiti 32 mesta u nizu jer se nulti ne koristi. */
#define DIM 32

/* Ucitavanje dimenzije i elemenata niza. */
int ucitavanje(int niz[])
{
	int i, n;

	printf("Unesite dimenziju niza: ");
	scanf("%d", &n);
	
	if (n<=0 || n>DIM)
	{
		printf("Nedozvoljena dimenzija niza.\n");
		exit(EXIT_FAILURE);
	}

	printf("Unesite broj prodatih artikala: ");
	for(i=0; i<n; i++)
		scanf("%d", &niz[i]);

	return n;
}

int najduzi_neopadajuci(int a[], int n) 
{
	int i;
	/* Parametar u kome se cuva duzina serije. Na pocetku je duzina serije jednaka 1, odnosno, samo jedan element je u seriji. Kasnije, u petlji se ovaj broj moze uvecati. */
	int ts = 1;
	/* Parametar ns predstavlja duzinu najduze serije. Na pocetku se postavlja na 1, odnosno pretpostavlja se da je duzina najduze serije 1, a u petlji se ova vrednost moze izmeniti. */
	int ns = 1;

	for (i = 1; i < n; i++) 
	{
		/* Proverava se da li uzastopni elementi ispunjavaju neopadajuci uslov. Ako je to slucaj uvecava se duzina serije. */
		if (a[i] >= a[i-1])
			ts++;
		else
		/* Ako uzastopni elementi nisu jednaki serija je prekinuta i paramtar za duzinu serije se postavlja ponovo na 1 da bi mogla da se racuna duzina sledece serije. */
			ts = 1;

		/* Ukoliko je trenutna duzina serije veca od duzine do sada najduze serije, parametar za duzinu najduze serije se postavlja na novu, vecu vrednost. */
		if (ts > ns)
			ns = ts;
	}
	
	return ns;
}

int main()
{
	int n, a[DIM];
	int i;

	n = ucitavanje(a);

	printf("Duzina najduzeg neopadajuceg prodavanja je %d.\n", najduzi_neopadajuci(a, n));

	return 0;
}
