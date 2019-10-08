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
  int i;
  float suma, clan, x, eps;

  /* Ucitavanje vrednosti x i eps. */
  printf("Unesite x: ");
  scanf("%f", &x);

  printf("Unesite tacnost eps: ");
  scanf("%f", &eps);

  /* Inicijalizacija sume, prvog clana i brojaca. */
  suma = 0;
  clan = 1;
  i = 1;

  /* U svakoj iteraciji na sumu se dodaje prethodno izracunati clan 
     sume i zatim se racuna sledeci clan. Petlja se prekida kada
     vrednost sledeceg clana postane manja ili jednaka eps. */
  while (clan > eps) {
    suma += clan;
    clan = clan * x / i;
    i++;
  }

  /* Ispis rezultata. */
  printf("S = %f\n", suma);

  return 0;
}
