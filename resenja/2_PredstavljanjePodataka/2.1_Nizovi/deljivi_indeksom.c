#include <stdio.h>

#define DIM 700

/* Funkcija pomera za jedno mesto u levo elemente niza a pocevsi od pozicije j. Element na poziciji j se brise i na njegovo mesto se upisuje element na poziciji j+1, a u skladu sa tim svi ostali elementi posle njega u nizu se pomeraju. */
void pomeri_za_jedno_mesto(int a[], int n, int j)
{
	int i;

	for(i=j; i<n; i++)
		a[i] = a[i+1];
}

int main()
{
	int n, niz[DIM], i;

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

	
	/* Potrebno je krenuti od poslednjeg elementa niza i petljom ici ka pocetku niza (element na poziciji 0 se ne razmatra). Proverava se da li je element potrebno obrisati i ako jeste vrsi se pomeranje elemenata niza za jedno mesto u levo. Prednost ovog resenja u odnosu na resenje kada se krene od pocetka niza je u tome sto element koji se ispituje sigurno nije promenio svoju poziciju usled pomeranja zbog brisanja. Problem se moze resiti i koriscenjem pomocnog niza (uraditi za vezbu). To resenje je efikasnije, ali trosi vise resursa. */	
   for(i=n-1; i>0; i--)
		if (niz[i]%i != 0)
		{
			pomeri_za_jedno_mesto(niz, n, i);
			/* Nakon brisanja elementa, smanjuje se i dimenzija niza. */
			n--;
		}


	/* Stampanje novog niza. */
	printf("Novi niz:\n");
	for(i=0; i<n; i++)
		printf("%d ", niz[i]);
	printf("\n");

	return 0;
}
