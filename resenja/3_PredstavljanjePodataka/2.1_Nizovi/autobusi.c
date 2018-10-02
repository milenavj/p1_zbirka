#include <stdio.h>

/* Indeksiranje pocinje od 1, pa zato maksimalna dimenzija niza mora biti 201, a ne 200. */
#define DIM 201

int main()
{
	int n, niz[DIM], i;
	int k, t;
	int m;

	/* Ucitavanje dimenzije i elemenata niza. */
	printf("Unesite dimenziju niza: ");
	scanf("%d", &n);
	
	if (n<=0 || n>DIM)
	{
		printf("Nedozvoljena dimenzija niza.\n");
		return 0;
	}

	printf("Unesite vreme putovanja:\n");
	for(i=1; i<=n; i++)
		scanf("%d", &niz[i]);

	/* Unos rednih brojeva autobusa. */
	printf("Unesite redne brojeve autobusa koji putuju na potezu Pozega, Uzice:\n");
	scanf("%d%d", &k, &t);

	if (k<=0 || k>n || t<=0 || t>n)
	{
		printf("Redni brojevi autobusa nisu u dozvoljenom opsegu.\n");
		return -1;
	}

	/* Unos vremena. */
	printf("Unesite novo vreme:\n");
	scanf("%d", &m);

	if (m < 0)
	{
		printf("Vreme ne moze biti negativno.\n");
		return -1;
	}
	
	/* Unos izmena u niz. */
	for(i=k; i<=t; i++)
		niz[i] += m;

	/* Ispis niza. */
	printf("Vreme putovanja nakon izmena:");
	for(i=1; i<=n; i++)
		printf("%d ", niz[i]);
	printf("\n");

	return 0;
}
