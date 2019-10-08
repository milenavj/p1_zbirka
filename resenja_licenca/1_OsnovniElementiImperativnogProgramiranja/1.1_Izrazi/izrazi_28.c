/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int x, p, c;
  unsigned int levo, desno, novo_x;

  /* Ucitavanje broja, pozicije i cifre. */
  printf("Unesite redom x, p i c: ");
  scanf("%u%u%u", &x, &p, &c);

  /* Racunanje dela broja koji se nalazi desno od pozicije p. 
     Funkcija pow kao povratnu vrednost vraca realan broj dvostruke
     tacnosti, a operacija % ocekuje celobrojne operande. Iz tog
     razloga je neophodno izvrsiti pretvaranje povratne vrednosti
     u tip unsigned int. */
  desno = x % (unsigned int) pow(10, p);

  /* Racunanje dela broja koji se nalazi levo od pozicije p. */
  levo = x / (unsigned int) pow(10, p);

  /* Racunanje rezultata nadovezivanjem levog dela, cifre c 
     i desnog dela. */
  novo_x =levo * (unsigned int) pow(10, p + 1) + 
         c * (unsigned int) pow(10, p) + desno;

  /* Ispis rezultata. */
  printf("Rezultat: %u\n", novo_x);

  return 0;
}
