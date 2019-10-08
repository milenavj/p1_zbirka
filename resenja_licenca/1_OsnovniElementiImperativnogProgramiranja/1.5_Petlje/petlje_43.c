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
  int i, n;
  float suma, x, clan;

  /* Ucitavanje vrednosti x i n. */
  printf("Unesite redom brojeve x i n: ");
  scanf("%f%d", &x, &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Inicijalizacije. */
  suma = 1;
  clan = 1;
  i = 2;

  /* Racunanje trazene sume. */
  while (i <= 2 * n) {
    /* Svaki clan sume se od prethodnog clana razlikuje za
       x^2/(i*(i-1)). */
    clan = clan * x * x / (i * (i - 1));
    clan *= -1;
    suma += clan;
    i += 2;
  }

  /* Ispis rezultata. */
  printf("S = %f\n", suma);

  return 0;
}
