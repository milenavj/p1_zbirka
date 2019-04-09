#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DUZINA	201
#define ZBIR	1000

int zbir(char* rec)
{
	int i = 0;
	int suma = 0;

	while(rec[i]) {
		suma += rec[i];
		i++;
	}

	return suma;
}

int main()
{
	/* Otvaranje datoteka za citanje i pisanje. */
	FILE *f = fopen("ulaz.txt", "r");
	FILE *g = fopen("izlaz.txt", "w");
	char rec[DUZINA];

	if (f == NULL) {
		printf("Ne postoji datoteka ulaz.txt\n");
		exit(EXIT_FAILURE);
	}

	if (g == NULL) {
		printf("Nije moguce kreirati datoteku izlaz.txt\n");
		exit(EXIT_FAILURE);
	}

	/* Rec po rec se ucitava iz datoteke. */
	while(fscanf(f, "%s", rec) != EOF) {
		if (zbir(rec) > ZBIR)
			fprintf(g, "%s ", rec);
	}



	fclose(f);
	fclose(g);
	return 0;
}