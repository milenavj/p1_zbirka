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
  float a, b, rezultat;
  float min, max;
  
  /* Ucitavanje vrednosti dva realna broja. */
  printf("Unesite dva realna broja: ");
  scanf("%f%f", &a, &b);

  /* Racunanje minimalne i maksimalne vrednost unetih brojeva. */
  min = (a < b) ? a : b;
  max = (a > b) ? a : b;

  /* Racunanje rezultata. */
  rezultat = (min + 0.5) / (1 + max * max);

  /* Ispis rezultata. */
  printf("Rezultat: %.2f\n", rezultat);

  return 0;
}
