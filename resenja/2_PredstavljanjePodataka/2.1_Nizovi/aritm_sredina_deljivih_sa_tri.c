#include <stdio.h>
#include <math.h>

#define DIM 200

/* Funkcija koja racuna aritmeticku sredinu onih elemenata niza koji su deljivi sa 3. */
float artmeticka_sredina_3(int niz[], int n)
{
	/* Brojac u petlji. */
	int i;
	/* Parametar koji predstavlja zbir svih elemenata deljivih sa 3. */
	int suma = 0;
	/* Parametar koji predstavlja brojih elemenata niza koji su deljivi sa 3. */
	int br_3 = 0;

	/* U petlji se proverava svaki element niza i za one koji su deljivi sa 3 uvecava se suma i odgovarajuci brojac. */
	for(i=0; i<n; i++)
		if (niz[i]%3 == 0)
		{
			suma += niz[i];
			br_3++;
		}

	return (float)suma/br_3;
}


int blizu_3(int a[], int n)
{
	/* Parametar koji predstavlja aritmeticku sredinu onih elemenata niza koji su deljivi sa 3. */
	float art = artmeticka_sredina_3(a, n);
	/* Pretpostavka je da je prvi element niza najblizi izracunatoj aritmetickoj sredini. */
	int element = a[0];
	/* Radi brzine izracunavanja pamti se razdaljina izmedju trenutno najblizeg elementa i aritmeticke sredine. Izracunava se apsolutna vrednost razdaljine jer ona moze biti i negativna. Moze se koristiti ugradjena funkcija fabs za racunanje apsolutne vrednosti realnih brojeva. */
	float razdaljina = fabs(art - element);
	/* Pomocni parametar koji sluzi da se u petlji pamti tekuca razdaljina. */
	float nova_razdaljina;
	/* Brojac u petlji. */
	int i;

	/* U petlji se ispituje svaki element niza i proverava se da li postoji neki koji je po vrednosti blizi aritmetickoj sredini. */
	for(i=1; i<n; i++)
	{
		nova_razdaljina = fabs(a[i] - art);
		/* Izracunava se razdaljina izmedju tekuceg elementa niza i poredi sa trenutnom razdaljinom. Ako je novodobijena vrednost manja vrsi se zamena zapamcenih parametara. */
		if (nova_razdaljina < razdaljina)
		{
			razdaljina = nova_razdaljina;
			element = a[i];
		}
	}
	
	return element;
}

int main()
{
	int niz[DIM], n, i;

	/* Ucitavanje dimenzije i elemenata niza. */
	printf("Unesite broj elemenata niza: ");
	scanf("%d", &n);
	
	if (n<=0 || n>DIM)
	{
		printf("Nedozvoljena dimenzija niza.\n");
		return 0;
	}

	printf("Unesite elemente niza: ");
	for(i=0; i<n; i++)
		scanf("%d", &niz[i]);

	/* Ispisivanje rezultata. */
	printf("Trazeni broj je %d.\n", blizu_3(niz, n));

	return 0;
}
