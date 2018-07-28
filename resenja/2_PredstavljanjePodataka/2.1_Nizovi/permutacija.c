#include <stdio.h>

#define DIM 100

void brojanje(int a[], int b[], int n)
{
	int i;

	/* Niz b se inicijalizuje nulama jer se za svaki element postavi da se poljavuljuje 0 puta u nizu a. */
   for(i=1; i<=n; i++)
		b[i] = 0;

   /* Peljom se prolazi kroz niz a i za svaki element a[i] uvecava se broj njegovog pojavljivanja u nizu b.
      Na primer, ako je a[3] = 7, onda treba uvecati broj pojavljivanja broja 7, a to je b[7]++, sto se
      krace moze zapisati kao b[a[3]]++.
      Pretpostavlja se da je niz a dobro zadat, odnosno da su sve njegove vrednosti u intervalu od 1 do n.
   */
	for(i=0; i<n; i++)
		b[a[i]]++;
}

int main()
{
	int a[DIM];
   /* Niz b moze imati index DIM (jer niz b se posmatra od 1 do DIM), pa zato njegova dimenzija mora biti za jedan veca. */
   int b[DIM+1];
	int i, n;

   /* Unos dimenzije i elemenata niza. */
	printf("Unesite broj elemenata niza: ");
	scanf("%d", &n);

	if (n <=0 || n > DIM)
	{
		printf("Neispravna dimenzija niza.\n");
		return -1;
	}

	printf("Unesite elemente niza:\n");
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
		/* Niz a moze sadrzati elemente koji nisu u opsegu od 1 do n. U tom slucaju taj niz nije permutacija. */
		if (a[i] <=0 || a[i] > n)
		{
			printf("Uneti niz nije permutacija.\n");
			return 0;
		}
	}
	
	brojanje(a, b, n);

	/* Ukoliko se svaki element niza a javlja tacno jednom u nizu a, onda niz a jeste permutacija. Ovo svojstvo se proverava koriscenjem dobijenog niza b. */
	for(i=1; i<=n; i++)	
		if (b[i] != 1)
		{
			printf("Uneti niz nije permutacija.\n");
			return 0;			
		}

	/* Ukoliko prethodna petlja nije ranije zavrsena (i nije se izaslo iz programa), onda svaki element niza b je jednak 1, odnosno svaki element se pojavljuje tacno jednom, pa niz a jeste permutacija. */
	printf("Uneti niz je permutacija.\n");

	return 0;
}
