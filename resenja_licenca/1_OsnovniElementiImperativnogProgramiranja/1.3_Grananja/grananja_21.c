/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float x, Fx;
  int k;

  /* Ucitavanje vrednosti x i k. */
  printf("Unesite redom x i k: ");
  scanf("%f %d", &x, &k);

  /* Provera ispravnosti ulaznih podataka. */
  if (k < 1 || k > 3) {
    printf("Greska: nedozvoljena vrednost za k.\n");
    return 0;
  }

  /* U zavisnosti od vrednosti k, data funkcija ce se izracunati
     jednom, dva puta ili tri puta. */
  Fx = 2 * cos(x) - x * x * x;
  if (k > 1)
    Fx = 2 * cos(Fx) - Fx * Fx * Fx;
  if (k > 2)
    Fx = 2 * cos(Fx) - Fx * Fx * Fx;

  /* Ispis rezultata. Napomena: Ispis realnih brojeva sa %g
     rezultuje ispisom na onaj broj decimala koliko sam broj ima.
     Dakle, broj 1 ce se ispisati kao 1, broj 2.33 kao 2.33, broj
     0.9999 kao 0.9999. */
  printf("F(%g, %d) = %.2f\n", x, k, Fx);

  return 0;
}
