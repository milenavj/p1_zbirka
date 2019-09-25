#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char c;

  /* Otvaranje datoteke podaci.txt za citanje i provera uspeha. */   
  ulaz = fopen("podaci.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje datoteke podaci.txt.");

  /* Otvaranje datoteke sifra.txt za pisanje i provera uspeha. */
  izlaz = fopen("sifra.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje datoteke sifra.txt.");

  /* Citanje karaktera iz ulazne datoteke. */
  while ((c = fgetc(ulaz)) != EOF) {
    /* Sifrovanje procitanog karaktera na trazeni nacin. */
    if (islower(c)) {
      c = toupper(c);
      if (c == 'A')
        c = 'Z';
      else
        c = c - 1;
    } else if (isupper(c)) {
      c = tolower(c);
      if (c == 'a')
        c = 'z';
      else
        c = c - 1;
    }

    /* Upisivanje izmenjenog karaktera u izlaznu datoteku. */
    fputc(c, izlaz);
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
