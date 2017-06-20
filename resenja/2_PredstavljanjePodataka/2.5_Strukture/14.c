#include <stdio.h>
#include <stdlib.h>

#define IME 21
#define OCENE 9
#define MAX_DJAKA 30

typedef struct
{
	char ime[IME];
	int ocena[OCENE];
}_djak;

void provera(int ocena)
{
	if (ocena < 1 || ocena > 5)
	{
		printf("Neispravna ocena.\n");
		exit(EXIT_FAILURE);
	}
}

int main()
{
	_djak niz[MAX_DJAKA];
	int i = 0, n, j;
	int suma;
	float prosek;
	
	printf("Uneti podatke o djaku: ");
	while(scanf("%s", niz[i].ime) != EOF && i < MAX_DJAKA)
	{
		for(j=0; j<9; j++)
		{
			scanf("%d", &niz[i].ocena[j]);
			provera(niz[i].ocena[j]);
		}

		i++;
    printf("Uneti podatke o djaku: ");
	}

	n = i;

	printf("\n\nNEDOVOLJNI: ");
	for(i=0; i<n; i++)
		for(j=0; j<9; j++)
			if (niz[i].ocena[j] == 1)
			{
				printf("%s ", niz[i].ime);
				break;
			}
	printf("\n");


	printf("ODLICNI: ");
	for(i=0; i<n; i++)
	{
		suma = 0;		
		for(j=0; j<9; j++)
			suma += niz[i].ocena[j];

		prosek = (float)suma/9;

		if (prosek >= 4.5)
			printf("%s ", niz[i].ime);
	}
	printf("\n");

	return 0;
}
