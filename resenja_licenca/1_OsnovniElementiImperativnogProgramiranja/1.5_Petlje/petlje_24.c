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
  int n, cifra, pozicija;
  unsigned int rezultat;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Inicijalizacija pozicije i rezultata. Pozicija oznacava tezinu 
     trenutne cifre i moze imati vrednosti 1, 10, 100, 1000, ... */
  pozicija = 1;
  rezultat = 0;

  /* Izdvajanje cifre po cifre broja sve dok ima neobradjenih
     cifara. */
  while (n > 0) {
    /* Izdvajanje poslednje cifre iz zapisa. U slucaju da je njena
       vrednost paran broj, izdvojena cifra se uvecava za 1. */
    cifra = n % 10;
    if (cifra % 2 == 0)
      cifra++;

    /* Novi broj se formira tako sto se izdvojena cifra pomnozi
       odgovarajucom tezinom (stepenom) pozicije i doda na tekuci
       rezultat. */
    rezultat += cifra * pozicija;

    /* Uklanjanje poslednje cifre broja. */
    n /= 10;

    /* Mnozenje pozicije sa 10. */
    pozicija *= 10;
  }

  /* Ispis izracunate vrednosti. */
  printf("Rezultat: %d\n", rezultat);

  return 0;
}
