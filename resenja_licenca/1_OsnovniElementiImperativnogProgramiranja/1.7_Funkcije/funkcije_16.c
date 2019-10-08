/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Funkcija proverava da li se cifre u zapisu broja nalaze u
   neopadajucem poretku. */
int neopadajuce(int n) {
  int tekuca_cifra, prethodna_cifra;
  n = abs(n);

  /* Izvan petlje se izdvaja poslednja cifra u zapisu broja da bi u
     petlji mogla da se poredi sa sledecom. */
  prethodna_cifra = n % 10;
  n /= 10;

  /* U petlji se proverava poredak svake dve susedne cifre. Ukoliko
     se detektuje da je poredak narusen, izlazi se iz funkcije i
     vraca se vrednost 0. */
  while (n) {
    tekuca_cifra = n % 10;

    if (tekuca_cifra > prethodna_cifra)
      return 0;

    /* Tekuca cifra postaje prethodna za narednu iteraciju. */
    prethodna_cifra = tekuca_cifra;
    n /= 10;
  }

  /* Nakon izlaska iz petlje povratna vrednost funkcije je 1 jer u
     slucaju da je poredak u nekom trenutku narusen iz funkcije bi
     se izaslo jos u petlji. */
  return 1;
}

int main() {
  /* Deklaracija potrebne promenljive. */
  int n;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Ispis odgovarajuce poruke. */
  if (neopadajuce(n))
    printf("Cifre su u neopadajucem poretku.\n");
  else
    printf("Cifre nisu u neopadajucem poretku.\n");

  return 0;
}
