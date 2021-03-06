/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

/* Funkcija obrce elemente niza. */
void obrni(int a[], int n) {
  int t, i, j;

  /* Za niz a[0], a[1], ...., a[n-2], a[n-1] obrnuti niz je a[n-1], 
     a[n-2], ...., a[1], a[0]. Zato je potrebno razmeniti vrednosti 
     elemenata a[0] i a[n-1], a[1] i a[n-2], itd. i zaustaviti se
     kada je vrednost indeksa prvog elementa veca od vrednosti
     drugog elementa. */
  for (i = 0, j = n - 1; i < j; i++, j--) {
    t = a[i];
    a[i] = a[j];
    a[j] = t;
  }
}

/* Funkcija rotira niz ciklicno za jedno mesto u levo. */
void rotiraj_za_1(int a[], int n) {
  int i, prvi = a[0];

  /* Pomeranje preostalih elemenata niza za jedno mesto u levo. */
  for (i = 0; i < n - 1; i++)
    a[i] = a[i + 1];

  /* Poslednjem elementu se dodeljuje sacuvana vrednost prvog
     elementa. */
  a[n - 1] = prvi;
}

/* Funkcija rotira niz ciklicno za k mesta u levo. */
void rotiraj_za_k(int a[], int n, int k) {
  int i;

  /* Odredjuje se vrednost broja k koja je u opsegu od 0 do n-1
     kako bi se izbegla suvisna pomeranja. */
  k = k % n;

  /* Niz se rotira za jednu poziciju ulevo k puta. */
  for (i = 0; i < k; i++)
    rotiraj_za_1(a, n);
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n, k;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n);

  /* Obrtanje niza. */
  printf("Elementi niza nakon obrtanja:\n");
  obrni(a, n);
  ispisi(a, n);

  /* Rotiranje za jedno mesto u levo. */
  printf("Elementi niza nakon rotiranja za 1 mesto ulevo:\n");
  rotiraj_za_1(a, n);
  ispisi(a, n);

  /* Rotiranje za k mesta u levo. */
  printf("Unesite jedan pozitivan ceo broj:");
  scanf("%d", &k);
  if (k <= 0) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  rotiraj_za_k(a, n, k);
  printf("Elementi niza nakon rotiranja za %d mesto ulevo:\n", k);
  ispisi(a, n);

  exit(EXIT_SUCCESS);
}
