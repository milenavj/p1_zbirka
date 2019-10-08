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
  float a, b, c;
  float obim, s, povrsina;

  /* Ucitavanje duzina stranica. */
  printf("Unesite duzine stranica trougla:\n");
  scanf("%f%f%f", &a, &b, &c);

  /* Racunanje obima. */
  obim = a + b + c;

  /* Racunanje povrsine koriscenjem Heronovog obrasca. */
  s = obim / 2;
  povrsina = sqrt(s * (s - a) * (s - b) * (s - c));

  /* Ispis rezultata. */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);

  return 0;
}
