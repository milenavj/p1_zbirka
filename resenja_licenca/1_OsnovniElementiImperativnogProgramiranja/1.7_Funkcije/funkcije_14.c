/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Funkcija uklanja cifru sa pozicije p iz broja n. Cifra jedinica
   ima poziciju 1, desetica 2, itd. */
int ukloni(int n, int p) {
  int znak, tezina_pozicije, levi_deo, desni_deo;

  /* Racunanje znaka broja n. */
  znak = n < 0 ? 1 : -1;

  /* Racunanje apsolutne vrednosti broja n. */
  n = abs(n);

  /* Racunanje tezina prosledjene pozicije. */
  tezina_pozicije = pow(10, p - 1);

  /* Broj se deli na dva dela - deo levo od cifre koja se izbacuje
     i deo desno od cifre koja se izbacuje. */
  levi_deo = n / (10 * tezina_pozicije);
  desni_deo = n % tezina_pozicije;

  /* Povratna vrednost funkcije se dobija spajanjem levog i desnog
     dela i mnozenjem znakom pocetnog broja. */
  return znak * (levi_deo * tezina_pozicije + desni_deo);
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int broj, p;

  /* Ucitavanje vrednosti pozicije. */
  printf("Unesite poziciju: ");
  scanf("%d", &p);

  /* Provera ispravnosti ulaza. */
  if (p <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Ucitavanje brojeva dok se ne unese nula i ispis brojeva
     dobijenih izbacivanjem cifre na poziciji p. */
  while (1) {
    printf("Unesite broj: ");
    scanf("%d", &broj);

    if (broj == 0)
      break;

    printf("Novi broj: %d\n", ukloni(broj, p));
  }

  return 0;
}
