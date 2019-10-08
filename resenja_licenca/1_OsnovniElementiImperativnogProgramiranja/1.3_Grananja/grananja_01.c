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
  int a, b, c, najmanji;

  /* Ucitavanje ulaznih vrednosti. */
  printf("Unesite tri cela broja: ");
  scanf("%d%d%d", &a, &b, &c);

  /* Inicijalizovanje najmanjeg broja na vrednost prvog broja. */
  najmanji = a;

  /* Azuriranje vrednosti minimuma u slucaju da je vrednost drugog
     broja manja od vrednosti tekuceg minimuma. */
  if (b < najmanji)
    najmanji = b;

  /* Ponavljanje postupka za treci broj. */
  if (c < najmanji)
    najmanji = c;

  /* Ispis rezultata. */
  printf("Najmanji: %d\n", najmanji);

  return 0;
}
