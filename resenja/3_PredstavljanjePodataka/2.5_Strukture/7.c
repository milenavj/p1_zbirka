#include <stdio.h>

#define MAX_DECE 200

typedef struct
{
	char pol;
	int broj_godina;
	int ocena;
}dete;

int main()
{
	int n, i, broj_godina;
	dete niz[MAX_DECE];
	char blanko, pol;
	int suma, broj_dece;

	printf("Uneti broj dece: ");
	scanf("%d", &n);

	if (n <= 0 || n > MAX_DECE)
	{
		printf("Neispravan broj dece.\n");
		return -1;
	}

	printf("Uneti podatke za svako dete, pol, broj godina i ocenu:\n");
	for(i=0; i<n; i++)
	{
		scanf("%c%c%d%d", &blanko, &niz[i].pol, &niz[i].broj_godina, &niz[i].ocena);

		/* Ispitivanje pogresnog unosa. */
		if (niz[i].pol != 'm' && niz[i].pol != 'z')
		{
			printf("Neispravan pol.\n");
			return -1;
		}
    if (niz[i].broj_godina > 6 || niz[i].broj_godina < 3)
		{
			printf("Neispravan broj godina.\n");
			return -1;
		}
		if (niz[i].ocena < 1 || niz[i].ocena > 5)
		{
			printf("Neispravna ocena.\n");
			return -1;
		}
	}

	printf("Uneti pol i broj godina: ");
	scanf("%c%c%d", &blanko, &pol, &broj_godina);

	/* Ispitivanje ispravnosti unetih podataka. */
  if (pol != 'm' && pol != 'z')
	{
		printf("Neispravan pol.\n");
		return -1;
	}
	if (broj_godina > 6 || broj_godina < 3)
	{
		printf("Neispravan broj godina.\n");
		return -1;
	}

	suma = 0;
	broj_dece = 0;

	for(i=0; i<n; i++)
		if (niz[i].pol == pol && niz[i].broj_godina == broj_godina)
		{
			suma += niz[i].ocena;
			broj_dece++;
		}

	if (broj_dece == 0)
		printf("Ne postoje deca sa takvim karakteristikama.\n");
	else
		printf("Prosecna ocena je: %.3lf.\n", (double)suma/broj_dece);

	return 0;
}
