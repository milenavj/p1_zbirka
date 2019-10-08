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

/* Funkcija brise sve elemente niza koji nisu deljivi svojom
   poslednjom cifrom. Povratna vrednost funkcije je broj elemenata
   rezultujuceg niza. */
int brisanje(int a[], int n) {
  int i, j, poslednja_cifra;

  /* Obilaze se svi elementi niza a. */
  for (i = 0, j = 0; i < n; i++) {
    /* Izdvajanje poslednja cifra tekuceg elementa. */
    poslednja_cifra = a[i] % 10;

    /* Ako je poslednja cifra nula ili je element deljiv svojom
       poslednjom cifrom, taj element se zadrzava i smesta na
       poziciju j. */
    if (poslednja_cifra == 0 || a[i] % poslednja_cifra == 0) {
      a[j] = a[i];
      j++;
    }
  }

  return j;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n);

  /* Brisanje svih elemenata koji nisu deljivi svojom poslednjom
     cifrom. */
  n = brisanje(a, n);

  /* Ispis rezultujuceg niza. */
  printf("Rezultujuci niz:\n");
  ispisi(a, n);

  exit(EXIT_SUCCESS);
}
