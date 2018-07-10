#include <stdio.h>

#define DIMENZIJA 10	

/* Funkcija za ucitavanje niza. */
void unos(int niz[])
{
	int i;

	printf("Unesite %d brojeva:\n", DIMENZIJA);
	for(i=0; i<DIMENZIJA; i++)
		scanf("%d", &niz[i]);
}

/* Funkcija za ispis niza. */
void ispis(int niz[], int n)
{
	int i;

	for(i=0; i<DIMENZIJA; i++)
		printf("%d ", niz[i]);

	printf("\n");
}

int main()
{
	int niz[DIMENZIJA];
	/* Brojaci i i j. Brojac i krece od pocetka niza, a brojac j od kraja. */
	int i=0, j = DIMENZIJA-1;
	/* Pomocna promenljiva za razmenu elemenata niza. */
	int pom;

	unos(niz);
	
    /* Ideja u resenju je da se krene sa dva kraja niza -- sa pocetka niza i sa kraja i
       svaki put kada se naidje na elemente koji po parnosti ne odgovaraju delu niza u kome treba da
       budu, ti elementi se zamene. */
	while(i < j && i < DIMENZIJA && j >= 0)
	{
		/* Ukoliko elementi na pozicijama i i j su razlicite parnosti,
           vrsi se razmena tih elemenata niza. */
		if (niz[i] % 2 != 0 && niz[j] % 2 == 0)
		{
			pom = niz[i];
			niz[i] = niz[j];
			niz[j] = pom;
		}

		/* Ukoliko je element na poziciji i paran, prelazi se na sledeci element niza,
           brojac i se uvecava. */
		if (niz[i] % 2 == 0)
			i++;

		/* Ukoliko je element na poziciji j neparan, prelazi se na sledeci element niza,
           brojac j se smanjuje. */
		if (niz[j] % 2 != 0)
			j--;
	}

	printf("Rezultujuci niz:\n");
	ispis(niz, DIMENZIJA);

	return 0;
}
