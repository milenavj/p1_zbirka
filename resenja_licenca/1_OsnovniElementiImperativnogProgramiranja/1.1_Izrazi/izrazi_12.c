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
  unsigned int x, obrnuto_x;
  char cifra_jedinice, cifra_desetice, cifra_stotine;

  /* Ucitavanje neoznacenog trocifrenog broja. */
  printf("Unesite trocifreni broj: ");
  scanf("%u", &x);

  /* Izdvajanje pojedinacnih cifara broja. */
  cifra_jedinice = x % 10;
  cifra_desetice = (x / 10) % 10;
  cifra_stotine = x / 100;

  /* Formiranje rezultujuceg broja. */
  obrnuto_x = cifra_jedinice * 100 + cifra_desetice * 10 + cifra_stotine;

  /* Ispis rezultata. */
  printf("Obrnuto: %u\n", obrnuto_x);

  return 0;
}
