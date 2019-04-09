#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DUZINA 21

int main()
{
	/* Otvaranje datoteka za citanje i pisanje. */
	FILE *ulaz, *izlaz;
	char c;
	char ime_datoteke1[DUZINA], ime_datoteke2[DUZINA];

	printf("Unesi ime datoteke: ");
	scanf("%s", ime_datoteke1);

	printf("Unesi ime datoteke: ");
	scanf("%s", ime_datoteke2);

	ulaz = fopen(ime_datoteke1, "r");
	izlaz = fopen(ime_datoteke2, "w");

	if (ulaz == NULL) {
		printf("Ne postoji datoteka plain.txt\n");
		exit(EXIT_FAILURE);
	}

	if (izlaz == NULL) {
		printf("Nije moguce kreirati datoteku sifra.txt\n");
		exit(EXIT_FAILURE);
	}

	while((c = fgetc(ulaz)) != EOF) {
		if (isdigit(c))
			fprintf(izlaz, "0");
		else if (isalpha(c))
			fprintf(izlaz, "1");
		else
			fprintf(izlaz, "2");
	}


	fclose(ulaz);
	fclose(izlaz);
	return 0;
}