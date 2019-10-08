/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS_TACAKA 50

/* Struktura koja opisuje tacku. */
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
  Tacka tacka, maks_tacka;
  double rastojanje, maks_rastojanje = -1;

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

  /* Citanje tacaka iz datoteke. */
  for (i = 0; i < n; i++) {
    fscanf(ulaz, "%d%d", &tacka.x, &tacka.y);

    /* Racunanje rastojanja tacke t od koordinatnog pocetka. */
    rastojanje = rastojanje_od_koordinatnog_pocetka(&tacka);

    /* Upisivanje izracunatog rastojanja u datoteku. */
    fprintf(izlaz, "%.2lf\n", rastojanje);

    /* Azuriranje maksimalnog rastojanja i odgovarajuce tacke. */
    if (rastojanje > maks_rastojanje) {
      maks_rastojanje = rastojanje;
      maks_tacka = tacka;
    }
  }

  /* Ispis rezultata. */
  printf("Najudaljenija tacka: (%d, %d)\n", maks_tacka.x, maks_tacka.y);

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
