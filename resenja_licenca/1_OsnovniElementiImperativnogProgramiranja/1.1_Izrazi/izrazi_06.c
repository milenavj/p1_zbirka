/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija promenljivih cija je vrednost neoznacen ceo broj. */
  unsigned int cena, kolicina, iznos, kusur;

  /* Ucitavanje vrednosti cene, kolicine i iznosa. */
  printf("Unesite cenu, kolicinu i iznos:\n");
  scanf("%u%u%u", &cena, &kolicina, &iznos);

  /* Racunanje kusura. */
  kusur = iznos - kolicina * cena;

  /* Ispis vrednosti kusura. */
  printf("Kusur: %u dinara\n", kusur);

  return 0;
}
