/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

/* Funkcija iscrtava romb. */
void romb(int n) {
  int i, j;

  /* Petlja iscrtava liniju po liniju romba. */
  for (i = 0; i < n; i++) {
    /* Ispis n-i-1 praznina. */
    for (j = 0; j < n - i - 1; j++)
      printf(" ");

    /* Ispis n zvezdica. */
    for (j = 0; j < n; j++)
      printf("*");

    /* Prelazak u sledeci red. */
    printf("\n");
  }
}

int main() {
  /* Deklaracija potrebne promenljive. */
  int n;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Iscrtavanje romba. */
  romb(n);

  return 0;
}
