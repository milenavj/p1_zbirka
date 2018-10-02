#include <stdio.h>
#include <string.h>

#define IME 21
#define PREZIME 31
#define EMAIL 51

#define MAX_OSOBA 50

typedef struct
{
	char ime[IME];
	char prezime[PREZIME];
	char email[EMAIL];
}Osoba;

int gmail(char* s)
{
	char* deo = strtok(s, "@");
	deo = strtok(NULL, "");

	if (strcmp(deo, "gmail.com") == 0)
		return 1;
	else
		return 0;
}

int main()
{
	int n, i;
	Osoba osobe[MAX_OSOBA];

	printf("Uneti broj osoba: ");
	scanf("%d", &n);

	if (n < 0 || n >= MAX_OSOBA)
	{
		printf("Greska u broju osoba.\n");
		return -1;
	}

	printf("Uneti podatke o osobama, ime, prezime i email.\n");
	for(i=0; i<n; i++)
		scanf("%s%s%s", osobe[i].ime, osobe[i].prezime, osobe[i].email);

	printf("Vlasnici gmail naloga su:\n");
	for(i=0; i<n; i++)
		if (gmail(osobe[i].email))
			printf("%s %s\n", osobe[i].ime, osobe[i].prezime);

	return 0;
}
