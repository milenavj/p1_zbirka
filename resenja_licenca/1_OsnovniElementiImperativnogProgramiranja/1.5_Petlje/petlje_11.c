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
  int n, suma, n_kopija;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Pravljenje kopije originalnog broja, da bi originalna vrednost n 
     ostala nepromenjena. */
  n_kopija = n;

  /* Inicijalizacija sume cifara. */
  suma = 0;

  /* Racunanje sume cifara. */
  while (n_kopija != 0) {
    /* Dodavanje poslednje cifre na sumu. */
    suma += n_kopija % 10;
    /* Uklanjanje poslednje cifre. */
    n_kopija /= 10;
  }

  /* Ispis rezultata. */
  if (n % suma == 0)
    printf("Broj %d je deljiv sa %d.\n", n, suma);
  else
    printf("Broj %d nije deljiv sa %d.\n", n, suma);

  return 0;
}
