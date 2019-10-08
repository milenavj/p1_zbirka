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
  unsigned int duzina, sirina, visina, cena;
  float povrsina_za_krecenje, ukupna_cena;

  /* Ucitavanje vrednosti duzine, sirine i visine sobe. */
  printf("Unesite dimenzije sobe: ");
  scanf("%u%u%u", &duzina, &sirina, &visina);

  /* Ucitavanje vrednosti cene krecenja. */
  printf("Unesite cenu po m2: ");
  scanf("%u", &cena);

  /* Povrsina za krecenje odgovara povrsini kvadra 
     umanjena za povrsinu poda jer se on ne kreci. */
  povrsina_za_krecenje = 0.8 * (duzina * sirina +
    2 * duzina * visina + 2 * sirina * visina);
  
  /* Racunanje ukupne cene. */
  ukupna_cena = povrsina_za_krecenje * cena;

  /* Ispis rezultata. */
  printf("Moler treba da okreci %.2f m2\n", povrsina_za_krecenje);
  printf("Cena krecenja: %.2f\n", ukupna_cena);

  return 0;
}
