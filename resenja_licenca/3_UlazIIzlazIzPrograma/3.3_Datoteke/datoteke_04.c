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
  char c;
  char ime_datoteke1[MAKS_IME], ime_datoteke2[MAKS_IME];

  /* Ucitavanje imena datoteka. */
  printf("Unesite ime prve datoteke: ");
  scanf("%s", ime_datoteke1);
  printf("Unesite ime druge datoteke: ");
  scanf("%s", ime_datoteke2);

  /* Otvaranje prve datoteke za citanje i provera uspeha. */
  ulaz = fopen(ime_datoteke1, "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje prve datoteke.");

  /* Otvaranje druge datoteke za pisanje i provera uspeha. */
  izlaz = fopen(ime_datoteke2, "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje druge datoteke.");

  /* Iz datoteke se cita karakter po karakter i za svaku procitanu
     cifru u izlaznu datoteku se upisuje 0, za svako slovo 1, a za
     ostale karaktere 2. */
  while ((c = fgetc(ulaz)) != EOF) {
    if (isdigit(c))
      fprintf(izlaz, "0");
    else if (isalpha(c))
      fprintf(izlaz, "1");
    else
      fprintf(izlaz, "2");
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  exit(EXIT_SUCCESS);
}
