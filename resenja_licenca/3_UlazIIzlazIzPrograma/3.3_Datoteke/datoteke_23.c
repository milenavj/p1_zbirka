/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAKS_RAZLOMAKA 100

/* Struktura koja opisuje razlomak. */
typedef struct {
  int brojilac;
  int imenilac;
} Razlomak;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija ucitava razlomke u niz razlomaka i kao povratnu
   vrednost vraca broj ucitanih razlomaka. */
int ucitaj_razlomke(Razlomak niz[], FILE *f) {
  int i, n;
  fscanf(f, "%d", &n);

  for (i = 0; i < n; i++) {
    fscanf(f, "%d %d", &niz[i].brojilac, &niz[i].imenilac);
    if (niz[i].imenilac == 0)
      greska("Greska: Imenilac ne moze biti 0.");
  }
  return n;
}

/* Funkcija racuna razlomak reciprocan razlomku r. */
Razlomak reciprocni(const Razlomak *r) {
  if (r->brojilac == 0)
    greska("Greska: nije moguce izracunati reciprocni razlomak.");

  Razlomak r2;
  r2.imenilac = r->brojilac;
  r2.brojilac = r->imenilac;
  return r2;
}

/* Funkcija racuna brojevnu vrednost razlomka r. */
float vrednost(const Razlomak *r) {
  return 1.0 * r->brojilac / r->imenilac;
}

int main(int argc, char *argv[]) {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  int i, n, opcija_x = 0, opcija_y = 0;
  Razlomak razlomci[MAKS_RAZLOMAKA];
  Razlomak r;

  /* Provera broja argumenata komandne linije. */
  if (argc != 4)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Otvaranje izlazne datoteke za pisanje i provera uspeha. */
  izlaz = fopen(argv[2], "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Ucitavanje zadate opcije i postavljanje vrednosti
     odgovarajuceg indikatora. */
  if (strcmp(argv[3], "-x") == 0)
    opcija_x = 1;
  else if (strcmp(argv[3], "-y") == 0)
    opcija_y = 1;
  else if (strcmp(argv[3], "-xy") == 0
           || strcmp(argv[3], "-yx") == 0)
    opcija_x = opcija_y = 1;
  else
    greska("Greska: neispravna opcija.");

  /* Ucitavanje podataka o razlomcima. */
  n = ucitaj_razlomke(razlomci, ulaz);

  /* Prolazak kroz niz razlomaka. */
  for (i = 0; i < n; i++) {
    /* Racunanje reciprocnog razlomka. */
    r = reciprocni(&razlomci[i]);

    /* Ispis rezultata u zavisnosti od navedenih opcija. */
    if (opcija_x)
      fprintf(izlaz, "%d/%d ", r.brojilac, r.imenilac);
    if (opcija_y)
      fprintf(izlaz, "%f ", vrednost(&r));
    fprintf(izlaz, "\n");
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  exit(EXIT_SUCCESS);
}
