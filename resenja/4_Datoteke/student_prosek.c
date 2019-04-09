#include <stdio.h>
#include <stdlib.h>

#define IME_PREZIME 	101
#define MAX_O			10
#define MAX_STUDENTA	100

typedef struct {
	char ime_i_prezime[IME_PREZIME];
	int ocene[MAX_O];
	int br_ocena;
	float prosek;
}student;

int main(int argc, char** argv)
{
	FILE *ulaz;
	char ime[IME_PREZIME], prezime[IME_PREZIME];
	int i = 0;
	student niz[MAX_STUDENTA];

	if (argc != 2) {
		printf("Nedovoljno argumenata komandne linije\n");
		exit(EXIT_FAILURE);
	}

	ulaz = fopen(argv[1], "r");

	if (ulaz == NULL) {
		printf("Ne postoji datoteka plain.txt\n");
		exit(EXIT_FAILURE);
	}

	while(fscanf(f, "%s%s", ime, prezime) != EOF) {
		strcpy()
	}


	return 0;
}