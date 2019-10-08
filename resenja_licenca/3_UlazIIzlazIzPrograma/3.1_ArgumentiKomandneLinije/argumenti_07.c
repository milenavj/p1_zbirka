/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main(int argc, char *argv[]) {
  /* Deklaracija potrebnih promenljivih. */
  int i, j, prikazi_poruku = 0;

  /* Prolazi se kroz sve argumente komandne linije. */
  for (i = 1; i < argc; i++) {
    /* Ukoliko argument pocinje karakterom '-', znaci da se navode
       opcije. */
    if (argv[i][0] == '-') {
      /* Ukoliko je u pitanju prvi niz opcija, ispisuje se
         odgovarajuca poruka i vrednost promenljive prikazi_poruku
         se postavlja na 1. */
      if (!prikazi_poruku) {
        printf("Opcije su: ");
        prikazi_poruku = 1;
      }

      /* Ispisuju se sve opcije, tj. svi karakteri argumenta
         argv[i] koji se nalaze nakon '-'. */
      for (j = 1; argv[i][j]; j++)
        printf("%c ", argv[i][j]);
    }
  }

  /* Ukoliko je vrednost promenljive prikazi_poruku nakon petlje 0,
     znaci da nije navedena nijedna opcija. */
  if (!prikazi_poruku)
    printf("Medju argumentima nema opcija.\n");
  else
    printf("\n");

  return 0;
}
