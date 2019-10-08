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

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija racuna broj cifara broja x. */
int broj_cifara(int x) {
  int brojac = 0;

  do {
    brojac++;
    x /= 10;
  } while (x);

  return brojac;
}

/* Funkcija broji koliko ima k-tocifrenih brojeva u datoteci f. */
int prebrojavanje(FILE *f, int k) {
  int n, broj, i, brojac;

  /* Ucitavanje broja brojeva u datoteci. */
  fscanf(f, "%d", &n);
  if (n <= 0)
    greska("Greska: neispravna vrednost broja n.");

  /* Cita se broj po broj i za svaki procitani broj se racuna broj
     cifara. Ukoliko je on jednak k, uvecava se odgovarajuci
     brojac. */
  brojac = 0;
  for (i = 0; i < n; i++) {
    fscanf(f, "%d", &broj);
    if (broj_cifara(broj) == k)
      brojac++;
  }

  /* Povratna vrednost funkcije je broj k-tocifrenih brojeva. */
  return brojac;
}

int main(int argc, char *argv[]) {
  /* Deklaracije potrebnih promenljivih. */
  int k;
  FILE *ulaz;

  /* Provera broja argumenata komandne linije. */
  if (argc != 3)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Citanje broja k i provera ispravnosti. */
  k = atoi(argv[2]);
  if (k <= 0)
    greska("Greska: neispravna vrednost broja k.");

  /* Ispis rezultata. */
  printf("Broj %d-cifrenih brojeva: %d\n", k,
         prebrojavanje(ulaz, k));

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
