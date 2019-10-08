/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  /* Deklaracija potrebnih promenljivih. */
  int n, i;

  /* Provera broja argumenata komandne linije. */
  if (argc != 2) {
    printf("Greska: neispravan poziv.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje broja n i cuvanje njegove apsolutne vrednosti. */
  n = atoi(argv[1]);
  n = abs(n);

  /* Ispis rezultata. */
  for (i = -n; i <= n; i++)
    printf("%d ", i);
  printf("\n");

  exit(EXIT_SUCCESS);
}
