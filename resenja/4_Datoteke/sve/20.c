#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS_TACAKA 50

typedef struct {
  int x, y;
} Tacka;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija racuna rastojanje tacke od koordinatnog pocetka. */
double rastojanje_od_koordinatnog_pocetka(const Tacka *a) {
  return sqrt(pow(a->x, 2) + pow(a->y, 2));
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  int n, i;
  Tacka tacka, maks_t;
  double rastojanje, maks_r = -1;

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen("tacke.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Otvaranje izlazne datoteke za pisanje i provera uspeha. */
  izlaz = fopen("rastojanja.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Ucitavanje broja tacaka i provera ispravnosti. */
  fscanf(ulaz, "%d", &n);
  if (n < 0 || n > MAKS_TACAKA)
    greska("Greska: neispravan broj tacaka.");

  /* Iz datoteke se cita tacka po tacka. */
  for (i = 0; i < n; i++) {
    fscanf(ulaz, "%d%d", &tacka.x, &tacka.y);

    /* Racunanje rastojanja tacke t od koordinatnog pocetka. */
    rastojanje = rastojanje_od_koordinatnog_pocetka(&tacka);

    /* Upisivanje izracunatog rastojanja u datoteku. */
    fprintf(izlaz, "%.2lf\n", rastojanje);

    /* Ukoliko je tekuce rastojanje  od trenutno najveceg
       rastojanja, azuriraju se vrednosti maksimanog rastojanja
       i odgovarajuce tacke. */
    if (rastojanje > maks_r) {
      maks_r = rastojanje;
      maks_t = tacka;
    }
  }

  /* Ispis rezultata. */
  printf("Najudaljenija tacka: (%d, %d)\n", maks_t.x, maks_t.y);

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  return 0;
}
