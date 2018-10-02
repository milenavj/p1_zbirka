#include <stdio.h>

#define DIM 2000

/* Funkcija za ispis elemenata niza. */
void ispis(int niz[], int n)
{
	int i;
	
	for(i=0; i<n; i++)
		printf("%d ", niz[i]);
	printf("\n");
}

/* Funkcija za ubacivanje na kraj niza. Vraca novu dimenziju niza. */
int ubaci_na_kraj(int niz[], int n, int x)
{
	niz[n] = x;
	return n+1;
}

/* Funkcija za ubacivanje na pocetak niza. Vraca novu dimenziju niza. */
int ubaci_na_pocetak(int niz[], int n, int x)
{
	int i;

	/* Prvo se svi elementi niza pomere za jednu poziciju u desno da bi se oslobodio prostor za prvi element niza. Poslednji element niza se pomera sa pozicije (n-1) na poziciju (n). Slicno se pomeraju i ostali elementi. */
	for(i=n; i>0; i--)
		niz[i] = niz[i-1];

	/* Na prvu poziciju se upisuje novi element. Bitan je redosled naredbi: ako bi prvo bio upisan novi element, a tek onda izvrseno pomeranje, element na poziciji niz[0] bi bio obrisan i ne bi mogao biti upisan na poziciju niz[1]. */
	niz[0] = x;

	return n+1;
}


/* Funkcija za ubacivanje elementa na neku poziciju u nizu. Vraca novu dimenziju niza. */
int ubaci_na_poziciju(int niz[], int n, int x, int pozicija)
{
	int i;

	/* Prvo se svi elementi niza od pozicije do kraja pomere za jedno mesto u desno da bi se oslobodio prostor za novi element niza.  */
	for(i=n; i>pozicija; i--)
		niz[i] = niz[i-1];

	/* Na poziciju se upisuje novi element. */
	niz[pozicija] = x;

	return n+1;
}

/* Funkcija za brisanje prvog elementa niza. Vraca novu dimenziju niza. */
int brisi_prvog(int niz[], int n)
{
	int i;

   /* Svi elementi niza pomeraju se za jedno mesto u levo. */
	for(i=0; i<n-1; i++)
		niz[i] = niz[i+1];

	return n-1;
}

/* Funkcija za brisanje poslednjeg elementa niza. Vraca novu dimenziju niza. */
int brisi_poslednjeg(int niz[], int n)
{
	/* Dovoljno je smanjiti dimenziju niza, elemente niza nije potrebno brisati. */
	return n-1;
}

/* Funkcija za brisanje elementa niza. Pretpostavlja se da element ima samo jedno pojavljivanje (za vezbu napisati funkciju koja brise sva pojavljivanja, ako ih ima vise). Vraca novu dimenziju niza. */
int brisi_element(int niz[], int n, int x)
{
	int i, j;

   /* Prvo treba pronaci poziciju elementa u nizu. */
	for(i=0; i<n; i++)
		if (niz[i] == x)
			break;

	/* Provera da li element postoji u nizu. Ako je brojac stigao do kraja niza, onda element ne postoji u nizu. */
	if (i == n)
	{
		printf("Klijent sa rednim brojem %d ne postoji u nizu.\n", x);
		return n;
	}

	/* Ukoliko element postoji u nizu, svi elementi niza nakon njega se pomeraju za jedno mesto u levo. */
	for(j = i; j<n-1; j++)
		niz[j] = niz[j+1];	

	return n-1;
}

int main()
{
	int n, niz[DIM], i, klijent, pozicija;

	/* Ucitavanje dimenzije i elemenata niza. */
	printf("Unesite trenutni broj klijenata: ");
	scanf("%d", &n);
	
	if (n<=0 || n>DIM)
	{
		printf("Nedozvoljena dimenzija niza.\n");
		return 0;
	}

	printf("Unesite niz sa rednim brojevima klijenata: ");
	for(i=0; i<n; i++)
		scanf("%d", &niz[i]);


   /* Ubacivanje klijenta na kraj. */
	printf("Unesite klijenta kojeg treba ubaciti u niz: ");
	scanf("%d", &klijent);
	n = ubaci_na_kraj(niz, n, klijent);
	printf("Niz nakon ubacivanja klijenta:\n");
	ispis(niz, n);

	/* Ubacivanje klijenta na pocetak. */
   printf("Unesite prioritetnog klijenta kojeg treba ubaciti u niz: ");
	scanf("%d", &klijent);
	n = ubaci_na_pocetak(niz, n, klijent);
	printf("Niz nakon ubacivanja klijenta:\n");
	ispis(niz, n);

	/* Ubacivanje klijenta na zadatu poziciju. */
   printf("Unesite prioritetnog klijenta kojeg treba ubaciti u niz i njegovu poziciju:");
	scanf("%d%d", &klijent, &pozicija);
   if (pozicija < 0 || pozicija > n)
	{
		printf("Neispravna pozicija.\n");
	}
	else
   {
		n = ubaci_na_poziciju(niz, n, klijent, pozicija);
		printf("Niz nakon ubacivanja klijenta:\n");
		ispis(niz, n);
	}

	/* Brisanje prvog klijenta. */	
   n = brisi_prvog(niz, n);
	printf("Niz nakon odlaska klijenta:\n");
	ispis(niz, n);

	/* Brisanje poslednjeg klijenta. */
	n = brisi_poslednjeg(niz, n);
	printf("Niz nakon odlaska klijenta:\n");
	ispis(niz, n);

	/* Brisanje klijenta sa datim rednim brojem. */
	printf("Unesite redni broj klijenta koji je napustio red: ");
	scanf("%d", &klijent);
	n = brisi_element(niz, n, klijent);
	printf("Niz nakon odlaska klijenta:\n");
	ispis(niz, n);

	return 0;
}
