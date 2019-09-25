#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_IME 21

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char ime_datoteke1[MAKS_IME], ime_datoteke2[MAKS_IME];
  char opcija, karakter;

  /* Ucitavanje imena datoteka i opcije. */
  printf("Unesite imena datoteka i opciju:");
  scanf("%s%s %c", ime_datoteke1, ime_datoteke2, &opcija);

  /* Provera ispravnosti opcije. */
  if (opcija != 'u' && opcija != 'l')
    greska("Greska: neispravan unos.");

  /* Otvaranje prve datoteke za citanje i provera uspeha. */
  ulaz = fopen(ime_datoteke1, "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje prve datoteke.");

  /* Otvaranje druge datoteke za pisanje i provera uspeha. */
  izlaz = fopen(ime_datoteke2, "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje druge datoteke.");

  /* Ako je uneta opcija 'u', svi karakteri se pretvaraju u velika
     slova, a ako je opcija 'l' u mala. Izmenjena slova se upisuju
     u izlaznu datoteku. */
  if (opcija == 'u')
    while ((karakter = fgetc(ulaz)) != EOF)
      fputc(toupper(karakter), izlaz);
  else
    while ((karakter = fgetc(ulaz)) != EOF)
      fputc(tolower(karakter), izlaz);

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
