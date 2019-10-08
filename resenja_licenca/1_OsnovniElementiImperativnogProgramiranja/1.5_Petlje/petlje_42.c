/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  double razlomak;

  /* Ucitavanje vrednosti broja n.  */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Razlomak se izracunava "od nazad", odnosno, krece se od
     najnizeg razlomka 1/n i od njega se nadalje formira sledeci,
     "visi" razlomak itd. Zavrsava se kada se stigne do koraka 0 +
     1/R. */
  razlomak = n;
  for (i = n - 1; i >= 0; i--)
    razlomak = i + 1 / razlomak;

  /* Ispis rezultata. */
  printf("R = %lf\n", razlomak);

  return 0;
}
