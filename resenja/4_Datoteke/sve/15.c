#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_REC 201
#define ZBIR 1000

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija racuna zbir ASCII kodova karaktera prosledjene reci. */
int zbir(char *rec) {
  int i = 0, suma = 0;

  while (rec[i]) {
    suma += rec[i];
    i++;
  }

  return suma;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char rec[MAKS_REC];

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen("ulaz.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Otvaranje izlazne datoteke za pisanje i provera uspeha. */
  izlaz = fopen("izlaz.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Iz datoteke se cita rec po rec i ukoliko je odgovarajuci zbir
     veci od vrednosti ZBIR, tada se rec ispisuje u izlaznu
     datoteku. */
  while (fscanf(ulaz, "%s", rec) != EOF)
    if (zbir(rec) > ZBIR)
      fprintf(izlaz, "%s ", rec);

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
