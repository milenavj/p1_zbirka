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
  int a, b, max;
  
  /* Ucitavanje dve celobrojne vrednosti. */
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &a, &b);

  /* Racunanje maksimuma koriscenjem ternarnog operatora. */
  max = (a > b) ? a : b;

  /* Ispis rezultata. */
  printf("Maksimum: %d\n", max);

  return 0;
}
