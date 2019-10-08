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
  float x, apsolutno_x;

  /* Ucitavanje vrednosti broja. */
  printf("Unesite jedan realan broj:");
  scanf("%f", &x);

  /* Racunanje apsolutne vrednosti unetog broja. */
  apsolutno_x = x;
  if (x < 0)
    apsolutno_x = -x;

  /* Ispis rezultata. */
  printf("Apsolutna vrednost: %.2f\n", apsolutno_x);

  /* II nacin: koriscenjem funkcije fabs cija se deklaracija nalazi 
     u zaglavlju math.h: apsolutno_x=fabs(x); */

  return 0;
}
