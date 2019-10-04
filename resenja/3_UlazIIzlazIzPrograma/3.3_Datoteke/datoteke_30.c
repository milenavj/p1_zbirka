#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_LINIJA 201

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  /* Deklaracije potrebnih promenljivih. */
  int i = 1;
  char *d1, *d2;
  FILE *ulaz1, *ulaz2;
  char linija1[MAKS_LINIJA], linija2[MAKS_LINIJA];

  /* Provera broja argumenata komandne linije. */
  if (argc != 3)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulaznih datoteka za citanje i provera uspeha. */     
  ulaz1 = fopen(argv[1], "r");
  ulaz2 = fopen(argv[2], "r");
  if (ulaz1 == NULL || ulaz2 == NULL)
    greska("Greska: neuspesno otvaranje datoteke.");

  /* Citanje prve linije iz obe datoteke. */
  d1 = fgets(linija1, MAKS_LINIJA, ulaz1);
  d2 = fgets(linija2, MAKS_LINIJA, ulaz2);

  /* Citanje preostalih linija dok se ne dodje do kraja bar jedne
     datoteke. */
  while (d1 != NULL && d2 != NULL) {
    /* Poredjenje ucitanih linija. */
    if (strcmp(linija1, linija2) != 0)
      printf("%d ", i);

    /* Prelazak na sledece linije. */
    d1 = fgets(linija1, MAKS_LINIJA, ulaz1);
    d2 = fgets(linija2, MAKS_LINIJA, ulaz2);

    i++;
  }

  /* Iz prethodne petlje je moglo da se izadje u 3 slucaja: 
     1. Doslo se do kraja prve datoteke. 
     2. Doslo se do kraja druge datoteke. 
     3. Doslo se do kraja obeju datoteka. 
     U slucaju da se desio treci slucaj, nijedna od naredne dve 
     petlje se nece izvrsiti. U prvom slucaju ce se izvrsiti samo
     prva petlja, a u drugom slucaju druga. */

  /* Ispis preostalih rednih brojeva linija prve datoteke. */
  while (d1 != NULL) {
    printf("%d ", i);
    d1 = fgets(linija1, MAKS_LINIJA, ulaz1);
    i++;
  }

  /* Ispis preostalih rednih brojeva linija druge datoteke. */
  while (d2 != NULL) {
    printf("%d ", i);
    d2 = fgets(linija2, MAKS_LINIJA, ulaz2);
    i++;
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz1);
  fclose(ulaz2);

  exit(EXIT_SUCCESS);
}
