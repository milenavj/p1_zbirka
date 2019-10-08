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
void ucitaj(float a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%f", &a[i]);
}

/* Funkcija racuna zbir prvih k pozitivnih elemenata niza. */
float zbir_pozitivnih(float a[], int n, int k) {
  int i;
  float zbir = 0;

  /* Obilazi se element po element niza. Postupak se zavrsava
     ukoliko se dodje do kraja niza ili ukoliko se sabere k
     pozitivnih elemenata. */
  for (i = 0; i < n && k > 0; i++)
    if (a[i] >= 0) {
      zbir += a[i];
      /* Umanjuje se brojac pozitivnih elemenata. */
      k--;
    }

  return zbir;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, k;
  float a[MAKS];

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n);

  /* Ucitavanje broja k i provera ispravnosti ulaza. */
  printf("Unesite vrednost k: ");
  scanf("%d", &k);
  if (k < 0 || k > n) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ispis rezultata. */
  printf("Zbir je: %.2f\n", zbir_pozitivnih(a, n, k));

  exit(EXIT_SUCCESS);
}
