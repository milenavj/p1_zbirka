/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

/* Funkcija vraca razlomljeni deo prosledjenog broja. */
float razlomljeni_deo(float x) {
  /* Napomena: Funkcija fabs racuna apsolutnu vrednost realnog
     broja i njena deklaracija se nalazi u zaglavlju math.h.
     Funkcija abs racuna apsolutnu vrednost celog broja i njena
     deklaracija se nalazi u zaglavlju stdlib.h. */
  x = fabs(x);

  /* Razlomljeni deo broja se dobija tako sto se od samog broja
     oduzme njegov ceo deo. */
  return x - (int) x;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  float n;

  /* Ucitavanje ulazne vrednosti. */
  printf("Unesite broj:");
  scanf("%f", &n);

  /* Ispis rezultata. */
  printf("Razlomljeni deo: %.6f\n", razlomljeni_deo(n));

  return 0;
}
