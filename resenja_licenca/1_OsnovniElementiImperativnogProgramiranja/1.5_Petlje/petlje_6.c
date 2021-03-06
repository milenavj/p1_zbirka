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
  float x, rezultat;

  /* Ucitavanje vrednosti brojeva x i n. */
  printf("Unesite redom brojeve x i n: ");
  scanf("%f %d", &x, &n);

  /* Provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: neispravan unos broja n.\n");
    return 1;
  }

  /* Inicijalizacija rezultata. */
  rezultat = 1;

  /* Vrednost n-tog stepena broja x se dobija tako sto se tekuca
     vrednost rezultata n puta pomnozi brojem x. 
     (rezultat = x * x * ... * x) = x^n */
  for (i = 0; i < n; i++)
    rezultat = rezultat * x;

  /* Ispis rezultata. */
  printf("Rezultat: %.5f\n", rezultat);

  return 0;
}
