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
  int n, i;
  float x, suma, x_i;

  /* Ucitavanje vrednosti x i n. */
  printf("Unesite redom brojeve x i n: ");
  scanf("%f %d", &x, &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0 || x == 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Inicijalizacija vrednosti sume na 0, a vrednosti x^i na x. */
  suma = 0;
  x_i = x;

  /* Promenljiva x^i ima vrednosti [x, x^2, ..., x^n]. Vrednost
     sume se u svakoj iteraciji uvecava za i*x^i. */
  for (i = 1; i <= n; i++) {
    suma += i * x_i;
    x_i *= x;
  }

  /* Ispis rezultata. */
  printf("S = %f\n", suma);

  return 0;
}
