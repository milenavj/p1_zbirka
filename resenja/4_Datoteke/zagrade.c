#include <stdio.h>
#include <stdlib.h>


int main(int argc, char** argv)
{
	/* Otvaranje datoteka za citanje i pisanje. */
	FILE *ulaz;
	char c;
	int broj_zagrada = 0;
	/* Na pocetku se pretpostavlja da zagrade jesu pravilno uparene. */
	int nisu_uparene = 0;

	if (argc != 2) {
		printf("Nedovoljno argumenata komandne linije\n");
		exit(EXIT_FAILURE);
	}

	ulaz = fopen(argv[1], "r");

	if (ulaz == NULL) {
		printf("Ne postoji datoteka plain.txt\n");
		exit(EXIT_FAILURE);
	}

	while((c = fgetc(ulaz)) != EOF) {
		if (c == '(')
			broj_zagrada++;
		else if (c == ')')
			broj_zagrada--;

		if (broj_zagrada < 0) {
			nisu_uparene = 1;
			break;
		}
	}

	if (broj_zagrada > 0 || broj_zagrada < 0 || nisu_uparene) 
		printf("Zagrade nisu pravilno uparene\n");
	else
		printf("Zagrade jesu pravilno uparene\n");


	fclose(ulaz);
	return 0;
}