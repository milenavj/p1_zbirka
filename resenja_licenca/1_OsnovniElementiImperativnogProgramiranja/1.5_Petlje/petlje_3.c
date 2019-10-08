/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int i, n;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: pogresan unos broja n.\n");
    return 1;
  }

  /* Inicijalizacija brojaca. */
  i = 0;

  /* Posto je potrebno ispisati sve brojeve [0,n], telo petlje se
     izvrsava za svako i <= n. */
  while (i <= n) {
    /* Ispis trenutne vrednosti brojaca. */
    printf("%d\n", i);

    /* Prelazak na sledeci broj.  */
    i++;
  }

  return 0;
}
