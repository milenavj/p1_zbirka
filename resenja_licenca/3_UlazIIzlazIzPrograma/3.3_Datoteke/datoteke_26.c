/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_LINIJA 81

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  /* Deklaracije potrebnih promenljivih. */
  char linija[MAKS_LINIJA], najduza_linija[MAKS_LINIJA];
  int duzina, maks_duzina;
  FILE *ulaz;

  /* Provera broja argumenata komandne linije. */
  if (argc != 2)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Pronalazak najduze linija u datoteci. */
  maks_duzina = 0;
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) {
    duzina = strlen(linija);

    if (duzina > maks_duzina ||
        (duzina == maks_duzina && 
         strcmp(linija, najduza_linija) < 0)) {
      strcpy(najduza_linija, linija);
      maks_duzina = duzina;
    }
  }

  /* Ispis najduze linije na standardni izlaz. */
  printf("%s", najduza_linija);

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
