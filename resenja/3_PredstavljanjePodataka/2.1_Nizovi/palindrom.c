#include <stdio.h>
#include <ctype.h>

#define DIM 200

int main()
{
	int n, i;
	char niz[DIM], blanko;

	/* Ucitavanje dimenzije i elemenata niza. */
	printf("Unesite trenutni broj klijenata: ");
	scanf("%d", &n);
	
	if (n<=0 || n>DIM)
	{
		printf("Nedozvoljena dimenzija niza.\n");
		return 0;
	}

   /* Nakon unosa dimenzije, korisnik unosi blanko ili znak za novi red. Ovaj karakter je potrebno ucitati pre unosa elemenata niza, inace ce ovaj karakter biti prvi element niza, sto nije zeljeno ponasanje. */
   scanf("%c", &blanko);

	printf("Unesite elemete niza: ");
	for(i=0; i<n; i++)
		scanf("%c", &niz[i]);

	/* Provera da li je niz palindrom. Uporedjuju se prvi i poslednji, drugi i pretposlednji... odnosno i-ti i ((n-1)-i)-ti element niza. Ako nisu jednaki, niz nije palindrom. Kako se istovremeno posmatraju dva elementa niza dovoljno je da brojac u petlji ide do polovine dimenzije niza.*/
   for(i=0; i<n/2; i++)
		/* Kako se zanemaruje velicina slova, svaki element niza se pretvara u malo slovo i potom se vrsi uporedjivanje. Ako je element niza veliko slovo, on ce biti pretvoren u malo; ako nije veliko slovo, element nece biti promenjen. Moglo je se i drugacije resiti, recimo pretvaranjem svih slova u velika, sa funkcijom toupper. */
		if (tolower(niz[i]) != tolower(niz[n-1-i]))
		{
			printf("Niz nije palindrom.\n");
			/* Ukoliko niz nije palindrom, ispitivanje se moze prekinuti i izaci iz programa, dalje ispitivanje nije potrebno. */
			return 0;
		} 

	/* U sluacju kada je petlja zavrsena, a nije izaslo iz programa, niz jeste palindrom jer uslov nikada nije bio ispunjen. */
	printf("Niz jeste palindrom!\n"); 

	return 0;
}
