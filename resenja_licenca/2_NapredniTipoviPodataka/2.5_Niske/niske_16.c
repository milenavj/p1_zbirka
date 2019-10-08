/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS_NISKA 10

/* Funkcija racuna broj cifara broja n. */
int broj_cifara(int n) {
  int brojac = 0;
  do {
    brojac++;
    n /= 10;
  } while (n);

  return brojac;
}

/* Funkcija od prosledjenog broja formira nisku. */
void broj_u_nisku(int broj, char s[]) {
  int n, cifra, i;

  /* Promenljiva n cuva informaciju o duzini niske. Duzina niske
     odgovara broju cifara prosledjenog broja. Ukoliko je broj
     negativan, onda se duzina uvecava za 1 i na prvo mesto se
     upisuje znak '-'. */
  n = broj_cifara(broj);
  if (broj < 0) {
    s[0] = '-';
    n++;
  }

  /* U nastavku se radi sa apsolutnom vrednoscu broja. */
  broj = abs(broj);

  /* Cifre broja se upisuju u nisku s sa desna na levo. */
  s[n] = '\0';
  i = n - 1;
  do {
    /* Karakter koji odgovara trenutnoj cifri se dobija izrazom '0' 
       + cifra. Na primer, '0' + 5 je '5' jer se karakter '5'
       nalazi 5 mesta nakon karaktera '0' u ASCII tablici. */
    cifra = broj % 10;
    broj = broj / 10;
    s[i] = '0' + cifra;
    i--;
  } while (broj);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n;
  char s[MAKS_NISKA];

  /* Ucitavanje broja. */
  printf("Unesite ceo broj: ");
  scanf("%d", &n);

  /* Formiranje niske. */
  broj_u_nisku(n, s);

  /* Ispis rezultata. */
  printf("Rezultat: %s\n", s);

  exit(EXIT_SUCCESS);
}
