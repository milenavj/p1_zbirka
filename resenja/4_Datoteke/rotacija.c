#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DUZINA_RECI	101
#define IME_DAT 	21

void rotiraj(char* rec, unsigned int k, char* rezultat)
{
	unsigned int i;
	unsigned int n = strlen(rec);
	k = k % n;

	for(i=0; i<k; i++)
		rezultat[n-k+i] = rec[i];

	for(i=k; i<n; i++)
		rezultat[i-k] = rec[i];
		

	rezultat[n] = '\0';
}

int main()
{
	/* Otvaranje datoteka za citanje i pisanje. */
	FILE *ulaz, *izlaz;
	char ime_datoteke[IME_DAT];
	char rec[DUZINA_RECI];
	char rezultat[DUZINA_RECI];
	unsigned int k;

	printf("Unesi ime datoteke: ");
	scanf("%s", ime_datoteke);

	ulaz = fopen(ime_datoteke, "r");

	if (ulaz == NULL) {
		printf("Ne postoji datoteka plain.txt\n");
		exit(EXIT_FAILURE);
	}

	izlaz = fopen("rotirano.txt", "w");
	if (izlaz == NULL) {
		printf("Neuspesno kreiranje datoteke rotirano.txt\n");
		exit(EXIT_FAILURE);
	}

	printf("Unesi prirodan broj: ");
	scanf("%u", &k);

	/* Rec po rec se ucitava iz datoteke. */
	while(fscanf(ulaz, "%s", rec) != EOF) {
		rotiraj(rec, k, rezultat);
		fprintf(izlaz, "%s ", rezultat);
	}



	fclose(ulaz);
	fclose(izlaz);
	return 0;
}
