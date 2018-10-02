#include <stdio.h>

#define MAX_PRODAVNICA 50
#define DUZINA_RECI 21

typedef struct
{
	char prodavnica[DUZINA_RECI];
	double cena;
}podatak;

int main()
{
	podatak niz[MAX_PRODAVNICA];
	double zeljena;
	int n, i;

	printf("Uneti broj prodavnica: ");
	scanf("%d", &n);

	if (n <=0 || n > MAX_PRODAVNICA)
	{
		printf("Neispravan broj prodavnica.\n");
		return -1;
	}

	for(i=0; i<n; i++)
  {
		scanf("%s%lf", niz[i].prodavnica, &niz[i].cena);

		if (niz[i].cena <= 0)
		{
			printf("Neispravna cena.\n");
			return -1;
		}
	}

	printf("Uneti zeljenu cenu: ");
	scanf("%lf", &zeljena);

	printf("Povoljne prodavnice su:\n");
	for(i=0; i<n; i++)
		if (niz[i].cena <= zeljena)
			printf("%s\n", niz[i].prodavnica);

	return 0;
}
