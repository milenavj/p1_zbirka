/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija celobrojne promenljive. */
  int n;

  /* Ucitavanje vrednosti celog broja. */
  printf("Unesite ceo broj: ");
  scanf("%d", &n);
  
  /* Ispis kvadratne vrednosti unetog broja. */
  printf("Kvadrat: %d\n", n * n);
  
  /* Ispis kubne vrednosti unetog broja. */
  printf("Kub: %d\n", n * n * n);

  return 0;
}
