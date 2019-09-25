#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_REC 201

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija proverava da li je prosledjena rec palindrom. Pri
   proveri se ignorise razlika izmedju malih i velikih slova. */
int palindrom(char rec[]) {
  int i, n = strlen(rec);

  for (i = 0; i < n / 2; i++)
    if (tolower(rec[i]) != tolower(rec[n - i - 1]))
      return 0;

  return 1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char rec[MAKS_REC];

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen("razno.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Otvaranje izlazne datoteke za pisanje i provera uspeha. */
  izlaz = fopen("palindromi.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Iz datoteke se cita rec po rec i u izlaznu datoteku se upisuju
     reci koje su palindromi. */
  while (fscanf(ulaz, "%s", rec) != EOF)
    if (palindrom(rec))
      fprintf(izlaz, "%s ", rec);

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
