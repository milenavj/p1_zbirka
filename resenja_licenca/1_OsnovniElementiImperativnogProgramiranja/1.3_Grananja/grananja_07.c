/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  unsigned int godina;

  /* Ucitavanje vrednosti godine. */
  printf("Unesite godinu:");
  scanf("%u", &godina);

  /* Provera da li je godina prestupna i ispis odgovarajuce poruke.
     Godina je prestupna ukoliko vazi jedan od narednih uslova:
     1. da je deljiva sa 4, a nije sa 100 
     2. da je deljiva sa 400. */
  if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
    printf("Godina je prestupna.\n");
  else
    printf("Godina nije prestupna.\n");

  return 0;
}
