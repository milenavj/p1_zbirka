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
  int x;
  float reciprocno_x;

  /* Ucitavanje vrednosti broja x. */
  printf("Unesite jedan ceo broj:");
  scanf("%d", &x);

  /* Provera ispravnosti ulaznih podataka. Napomena: Za
     razliku od izlaza iz programa sa kodom 0 (return 0;) koji
     sluzi kao indikator da se program zavrsio uspesno, izlaz iz
     programa sa izlaznim kodom razlicitim od nule sluzi kao
     indikator da je pri izvrsavanju programa doslo do neke greske. */
  if (x == 0) {
    printf("Greska: nedozvoljeno je deljenje nulom.\n");
    return 1;
  }

  /* Racunanje reciprocne vrednosti. */
  reciprocno_x = 1.0 / x;

  /* Ispis rezultata. */
  printf("Reciprocna vrednost: %.4f\n", reciprocno_x);

  return 0;
}
