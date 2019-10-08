/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

/* Funkcija racuna broj cifara celog broja n. */
int broj_cifara(int n) {
  int brojac = 0;
  n = abs(n);

  if (n < 10)
    return 1;

  while (n) {
    brojac++;
    n /= 10;
  }

  return brojac;
}

/* Funkcija racuna broj koji se dobija rotacijom broja n za jedno
   mesto ulevo. */
int rotacija(int n) {
  int znak, prva_cifra, n_bez_prve_cifre, br_cifara;

  znak = (n < 0) ? -1 : 1;
  n = abs(n);
  br_cifara = broj_cifara(n);

  /* Izdvajaju se prva cifra i deo broja bez prve cifre. 
     Na primer: ako je n = 1234 onda je br_cifara = 4
     prva_cifra se dobija sa: 
     n / (10 ^ (br_cifara - 1)) = 1234 / 1000 = 1. 
     n_bez_prve_cifre se dobija sa: n % 1000 = 234. */
  int tezina_pozicije = pow(10, br_cifara - 1);
  prva_cifra = n / tezina_pozicije;
  n_bez_prve_cifre = n % tezina_pozicije;

  /* Rezultat se dobija nadovezivanjem prve cifre na kraj i
     mnozenjem znakom pocetnog broja. */
  return znak * (n_bez_prve_cifre * 10 + prva_cifra);
}

int main() {
  /* Deklaracija potrebne promenljive. */
  int n;

  /* Ucitavanje brojeva sve do unosa broja nula i ispis brojeva
     dobijenih kao rezultat izvrsavanja funkcije rotacija nad 
     unetim brojevima. */
  while (1) {
    printf("Unesite broj: ");
    scanf("%d", &n);

    if (n == 0)
      break;

    printf("Novi broj: %d\n", rotacija(n));
  }

  return 0;
}
