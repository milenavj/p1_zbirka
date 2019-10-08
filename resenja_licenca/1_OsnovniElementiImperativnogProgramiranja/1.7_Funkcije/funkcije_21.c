/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <math.h>

/* Funkcija racuna vrednost e^x kao parcijalnu sumu reda
   suma(x^n/n!), gde indeks n ide od od 0 do beskonacno, pri cemu
   se sumiranje sprovodi sve dok je sabirak po apsolutnoj vrednosti
   veci od date tacnosti eps. */
double e_na_x(double x, double eps) {
  double s = 1, clan = 1;
  int n = 1;

  /* Parcijalnu suma se formira tako sto se u svakoj iteraciji
     petlje promenljivoj s doda jedan sabirak sume oblika (x^n)/n!
     koji se cuva u promenljivoj clan.

     Svaki sabirak se dobija na osnovu prethodnog tako sto se
     prethodni pomnozi sa x i podeli sa n (n predstavlja redni broj 
     sabirka u sumi).

     Prvi sabirak (kome odgovara n=0) iznosi 1; zbog toga
     promenljive s i clan se inicijalizuju na vrednost 1.

     Sumiranje se sprovodi sve dok je sabirak po apsolutnoj
     vrednosti veci od date tacnosti eps. */
  do {
    clan = (clan * x) / n;
    s += clan;
    n++;
  } while (fabs(clan) > eps);

  return s;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  double x, eps;

  /* Ucitavanje vrednosti x i eps. */
  printf("Unesite broj x: ");
  scanf("%lf", &x);
  printf("Unesite eps: ");
  scanf("%lf", &eps);

  /* Ispis rezultata. */
  printf("Rezultat: %f\n", e_na_x(x, eps));
  return 0;
}
