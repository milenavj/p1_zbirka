/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS 1000

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija ispisuje elemente niza. */
void ispisi(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

/* Funkcija racuna sumu elemenata niza. */
int suma(int a[], int n) {
  int i, suma_elemenata = 0;
  
  for (i = 0; i < n; i++)
    suma_elemenata += a[i];
  
  return suma_elemenata;
}

/* Funkcija racuna prosecnu vrednost elemenata niza. */
float prosek(int a[], int n) {
  int suma_elemenata = suma(a, n);
  return (float) suma_elemenata / n;
}

/* Funkcija izracunava maksimum elemenata niza. */
int maksimum(int a[], int n) {
  int i, najveci = a[0];
  
  for (i = 1; i < n; i++)
    if (a[i] > najveci)
      najveci = a[i];

  return najveci;
}

/* Funkcija izracunava poziciju maksimalnog elementa u nizu. */
int pozicija_maksimuma(int a[], int n) {
  int i, pozicija_najveceg = 0;

  for (i = 1; i < n; i++)
    if (a[i] > a[pozicija_najveceg])
      pozicija_najveceg = i;

  return pozicija_najveceg;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza:");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n);

  /* Ispis elemenata niza. */
  printf("Vreme trcanja takmicara: ");
  ispisi(a, n);

  /* Ispis ukupnog, prosecnog i maksimalnog vremena. */
  printf("Ukupno vreme: %d\n", suma(a, n));
  printf("Prosecno vreme trcanja: %.2f\n", prosek(a, n));
  printf("Maksimalno vreme trcanja: %d\n", maksimum(a, n));

  /* Ispis indeksa pobednika. */
  printf("Indeks pobednika: %d\n", pozicija_maksimuma(a, n));

  exit(EXIT_SUCCESS);
}
