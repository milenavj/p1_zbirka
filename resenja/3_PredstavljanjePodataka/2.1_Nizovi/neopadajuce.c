#include <stdio.h>

#define DIM 300

int main()
{
	int n, niz[DIM], i;

	/* Ucitavanje dimenzije i elemenata niza. */
	printf("Unesite dimenziju niza: ");
	scanf("%d", &n);
	
	if (n<=0 || n>DIM)
	{
		printf("Nedozvoljena dimenzija niza.\n");
		return 0;
	}

	printf("Unesite elemente niza: ");
	for(i=0; i<n; i++)
		scanf("%d", &niz[i]);

	
	/* Provera da li su elementi niza uredjeni neopadajuce. */
	for(i=0; i<n-1; i++)
		/* Porede se svaka dva uzastopna elementa niza. Ukoliko za bilo koja takva dva elementa uslov nije ispunjen, prekida se dalje ispitivanje i vraca se poruka da niz nije uredjen neopadajuce. U suprotnom se nakon izlaska iz petlje ispisuje poruka da je niz uredjen neopadajuce. */
		if (niz[i] > niz[i+1])
		{
			printf("Nije uredjen neopadajuce.\n");
			return 0;
		}

	printf("Jeste uredjen neopadajuce!\n");

	return 0;
}
