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
void ispisi(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

/* Funkcija brise sve neparne elemente niza. */
int obrisi_neparne(int a[], int n) {
  int i, j;
  /* Promenljiva j predstavlja brojac prve slobodne pozicije na
     koju se moze upisati element niza koji treba da ostane u nizu. 
     Kada se naidje na element koji je paran, on se kopira na
     mesto a[j] i poveca se vrednost brojaca j. Ukoliko se naidje
     na element koji je neparan, njega treba preskociti. */
  for (i = 0, j = 0; i < n; i++) {
    /* Ako je tekuci element niza a paran. */
    if (a[i] % 2 == 0) {
      /* Premesta se na poziciju j. */
      a[j] = a[i];

      /* Vrednost brojaca j se priprema za narednu iteraciju. */
      j++;
    }
    /* Ako je tekuci element niza a neparan, sa njim nista ne treba 
       raditi. */
  }

  /* Rezultujuci niz ima j elemenata. */
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

  /* Brisanje neparnih elemenata niza. */
  n = obrisi_neparne(a, n);

  /* Ispis elemenata izmenjenog niza a. */
  printf("Rezultujuci niz:\n");
  ispisi(a, n);

  exit(EXIT_SUCCESS);
}
