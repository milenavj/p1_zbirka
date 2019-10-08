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

/* Funkcija proverava da li je broj Armstrongov. */
int armstrong(int x) {
  int suma = 0;
  int n = broj_cifara(x);
  int x_pocetno = x;

  /* Racunanje suma n-tih stepena cifara broja x. */
  while (x) {
    suma += pow(x % 10, n);
    x /= 10;
  }

  /* Ako je suma jednaka pocetnoj vrednosti broja x, broj je
     Armstrongov, u suprotnom nije. */
  return x_pocetno == suma;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  int x;

  /* Ucitavanje vrednosti broja x. */
  printf("Unesite broj: ");
  scanf("%d", &x);

  /* Ispis odgovarajuce poruke. */
  if (armstrong(x))
    printf("Broj je Armstrongov.\n");
  else
    printf("Broj nije Armstrongov.\n");

  return 0;
}
