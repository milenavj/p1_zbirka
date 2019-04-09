#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
	/* Otvaranje datoteka za citanje i pisanje. */
	FILE *f = fopen("plain.txt", "r");
	FILE *g = fopen("sifra.txt", "w");
	char c;

	if (f == NULL) {
		printf("Ne postoji datoteka plain.txt\n");
		exit(EXIT_FAILURE);
	}

	if (g == NULL) {
		printf("Nije moguce kreirati datoteku sifra.txt\n");
		exit(EXIT_FAILURE);
	}

	/* Karakter po karakter se ucitava iz datoteke. */
	while((c = fgetc(f)) != EOF) {
		/* Karakter koji je malo slovo se pretava u veliko slovo. */
		if (islower(c)) {
			c = toupper(c);
			if (c == 'A')
				c = 'Z';
			/* Karakter postavljamo na prethodni. */
			else
				c = c - 1;
		}
		else if (isupper(c)) {
			c = tolower(c);
			if (c == 'a')
				c = 'z';
			else
				c = c - 1;
		}

		fputc(c, g);
	}



	fclose(f);
	fclose(g);
	return 0;
}