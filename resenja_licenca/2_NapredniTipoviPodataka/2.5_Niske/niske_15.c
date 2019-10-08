/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_NISKA 10

/* Funkcija formiraj_broj na osnovu niske b formira ceo broj ciji
   je to zapis.

   Ako su cifre broja a, b, c i d, tada broj mozemo formirati kao:
   a*10^3 + b*10^2 + c*10^1 + d*10^0. Medjutim, efikasnije je
   koristiti Hornerovu semu: 10*(10*(10*(10*0 + a)+b)+c)+d. */
int formiraj_broj(char b[]) {
  int i;
  int broj = 0, znak;

  /* Odredjivanje znaka broja i pozicije prve cifre. */
  if (b[0] == '-') {
    znak = -1;
    i = 1;
  } else if (b[0] == '+') {
    znak = 1;
    i = 1;
  } else {
    i = 0;
    znak = 1;
  }

  /* Prolazak kroz cifre broja i racunanje vrednosti broja
     koriscenjem Hornerove sheme. Vrednost trenutne cifre se dobija
     kada se od trenutnog karaktera (b[i]) oduzme karakter '0'.
     Ako se naidje na karakter koji nije cifra, petlja se prekida. 
     Na primer, za b="123abc", rezultat treba da bude 123. */
  for (; b[i] != '\0'; i++) {
    if (isdigit(b[i]))
      broj = broj * 10 + (b[i] - '0');
    else
      break;
  }

  return broj * znak;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_NISKA];

  /* Broj se ucitava kao niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ispis rezultata. */
  printf("Rezultat: %d\n", formiraj_broj(s));

  /* II nacin: Koriscenjem funkcije atoi. Deklaracija ove funkcije
     se nalazi u zaglavlju stdlib.h.

     printf("%d\n", atoi(s)); */

  exit(EXIT_SUCCESS);
}
