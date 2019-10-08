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
  int i, prikazi_poruku = 0;

  /* Ispis svih argumenata komandne linije ciji je prvi karakter
     znak '@'. Ako se program pokrene sa: 
     ./a.out @pera mika @zika
     argv[0] je "./a.out" i on se preskace. 
     argv[1] je "@pera", a prvi karakter je onda argv[1][0]. 
     Dakle, za argv[i] treba proveravati da li je argv[i][0] jednak
     karakteru '@'. */
  for (i = 1; i < argc; i++) {
    if (argv[i][0] == '@') {
      /* Promenljiva prikazi_poruku sluzi da detektuje da li
         postoji bar jedna niska koja pocinje sa '@'. Ukoliko se
         naidje na prvu takvu nisku, ispisuje se trazena poruka i
         prikazi_poruku se postavlja na 1. */
      if (!prikazi_poruku) {
        printf("Argumenti koji pocinju sa @:\n");
        prikazi_poruku = 1;
      }
      printf("%s ", argv[i]);
    }
  }

  /* Ukoliko je vrednost promenljive prikazi_poruku i dalje 0,
     znaci da nijedan argument ne pocinje karakterom '@'. */
  if (!prikazi_poruku)
    printf("Nema argumenata koji pocinju sa @.");
  printf("\n");

  return 0;
}
