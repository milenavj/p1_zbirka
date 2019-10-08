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
  int n, i, suma_kubova;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n:");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Racunanje sume kubova svih brojeva iz intervala [1,n] i ispis
     vrednosti sume u svakoj iteraciji. */
  suma_kubova = 0;
  for (i = 1; i <= n; i++) {
    suma_kubova += i * i * i;
    printf("[k = %d] Suma kubova: %d\n", i, suma_kubova);
  }

  return 0;
}
