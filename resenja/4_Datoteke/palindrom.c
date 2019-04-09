#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define DUZINA 201

int palindrom(char* rec)
{
	int n = strlen(rec);
	int i;

	for(i =0; i<n/2; i++)
		if (tolower(rec[i]) != tolower(rec[n-i-1]))
			return 0;

	return 1;
}

int main()
{
	/* Otvaranje datoteka za citanje i pisanje. */
	FILE *f = fopen("razno.txt", "r");
	FILE *g = fopen("palindromi.txt", "w");
	char rec[DUZINA];

	if (f == NULL) {
		printf("Ne postoji datoteka razno.txt\n");
		exit(EXIT_FAILURE);
	}

	if (g == NULL) {
		printf("Nije moguce kreirati datoteku palindromi.txt\n");
		exit(EXIT_FAILURE);
	}

	/* Rec po rec se ucitava iz datoteke. */
	while(fscanf(f, "%s", rec) != EOF) {
		if (palindrom(rec))
			fprintf(g, "%s ", rec);
	}	



	fclose(f);
	fclose(g);
	return 0;
}