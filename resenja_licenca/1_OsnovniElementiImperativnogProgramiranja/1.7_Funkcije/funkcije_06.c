/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

/* Funkcija racuna zbir reciprocnih vrednosti brojeva iz intervala
   [1,n]. */
float zbir_reciprocnih(int n) {
  float zbir = 0;
  int i;

  /* Za svako i izmedju 1 i n na zbir se dodaje vrednost 1/i.
     Napomena: zbog celobrojnog deljenja mora da stoji 1.0/i. */
  for (i = 1; i <= n; i++)
    zbir += 1.0 / i;

  /* Kao povratna vrednost funkcije se vraca izracunati zbir. */
  return zbir;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  int n;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n:\n");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ispis rezultata. */
  printf("Zbir reciprocnih: %.2f\n", zbir_reciprocnih(n));

  return 0;
}
