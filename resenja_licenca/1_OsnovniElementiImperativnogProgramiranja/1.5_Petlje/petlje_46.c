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
  double x, a, rezultat;

  /* Ucitavanje vrednosti ulaznih promenljivih. */
  printf("Unesite brojeve x i a: ");
  scanf("%lf%lf", &x, &a);
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Racunanje vrednosti zadatog izraza. Krece se od 
     rezultat = (x + a) ^ 2 i ide se ka spolja.
     Svaki put vrednost rezultata treba zameniti sa 
     (rezultat + a) ^ 2. */
  rezultat = x;
  for (i = 0; i < n; i++)
    rezultat = (rezultat + a) * (rezultat + a);

  /* Ispis rezultata. */
  printf("Izraz = %lf\n", rezultat);

  return 0;
}
