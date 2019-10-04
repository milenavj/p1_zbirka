#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_IME 5

/* Struktura koja opisuje pravougaonik. */
typedef struct {
  unsigned int a, b;
  char ime[MAKS_IME];
} Pravougaonik;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int maksimalna_povrsina = 0;
  Pravougaonik p;

  /* Provera broja argumenata komandne linije. */
  if (argc != 2)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  FILE *ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Citanje podataka o pravougaonicima. */
  while (fscanf(ulaz, "%u%u%s", &p.a, &p.b, p.ime) == 3) {
    /* Provera ispravnosti duzina stranica. */
    if (p.a == 0 || p.b == 0)
      greska("Greska: duzina stranice ne moze biti 0.");

    /* U slucaju da je ucitan kvardat, njegovo ime se ispisuje na
       standardni izlaz. */
    if (p.a == p.b)
      printf("%s ", p.ime);
    else { /* Ako je u pitanju pravougaonik, njegova povrsina
              se poredi sa maksimalnom. */
      if (p.a * p.b > maksimalna_povrsina)
        maksimalna_povrsina = p.a * p.b;
    }
  }

  /* Ukoliko je bilo ucitanih pravougaonika, ispisuje se povrsina
     najveceg. */
  if (maksimalna_povrsina != 0)
    printf("%u\n", maksimalna_povrsina);
  else
    printf("\n");

  /* Zatvaranje datoteke. */
  fclose(ulaz);
  
  exit(EXIT_SUCCESS);
}
