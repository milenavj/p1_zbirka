#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DUZINA 21

int main()
{
	/* Otvaranje datoteka za citanje i pisanje. */
	FILE *ulaz;
	char c;
	char ime_datoteke[DUZINA];
	int niz[10];
	int i, max;

	printf("Unesi ime datoteke: ");
	scanf("%s", ime_datoteke);

	ulaz = fopen(ime_datoteke, "r");

	if (ulaz == NULL) {
		printf("Ne postoji datoteka plain.txt\n");
		exit(EXIT_FAILURE);
	}

	for(i=0; i<10; i++)
		niz[i] = 0;

	while((c = fgetc(ulaz)) != EOF) {
		if (isdigit(c))
			niz[c - '0']++;
	}

	max = 0;

	for(i=1; i<10; i++)
		if (niz[max] < niz[i])
			max = i;

	printf("%d\n", max);

	fclose(ulaz);
	return 0;
}