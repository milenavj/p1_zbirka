#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite podatke: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija proverava da li niz sadrzi zadatu vrednost m. */
int sadrzi(int a[], int n, int m) {
  int i;
  /* Prolazi se kroz sve elemente niza i ukoliko se naidje na
     element cija je vrednost jednaka m, kao povratna vrednost
     funkcije se vraca 1. */
  for (i = 0; i < n; i++)
    if (a[i] == m)
      return 1;

  /* Ako se stigne do kraja niza, znaci da se broj m ne nalazi
     u nizu. */
  return 0;
}

/* Funkcija vraca indeks prvog pojavljivanja elementa m u nizu a
   ili -1 ukoliko se m ne nalazi u nizu a. */
int prvo_pojavljivanje(int a[], int n, int m) {
  int i;
  for (i = 0; i < n; i++)
    if (a[i] == m)
      return i;

  /* Ako se stigne do kraja niza, znaci da se broj m ne nalazi
     u nizu. */
  return -1;
}

/* Funkcija vraca indeks poslednjeg pojavljivanja elementa m u nizu 
   a ili -1 ukoliko se m ne nalazi u nizu a. */
int poslednje_pojavljivanje(int a[], int n, int m) {
  int i;

  /* Polazi se od kraja niza i poredi se element po element sa
     zadatim brojem m. */
  for (i = n - 1; i >= 0; i--)
    if (a[i] == m)
      return i;

  /* Ako se stigne do pocetka niza, znaci da se broj m ne nalazi
     u nizu. */
  return -1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS];
  int n, m, i;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n);

  /* Ucitavanje vrednosti za pretragu. */
  printf("Unesite vrednost m:");
  scanf("%d", &m);

  /* Ispis rezultata pretrage. */
  if (sadrzi(a, n, m)) {
    printf("Nadmorska visina %d se nalazi medju podacima.\n", m);

    i = prvo_pojavljivanje(a, n, m);
    printf("Pozicija prvog pojavljivanja: %d\n", i);

    i = poslednje_pojavljivanje(a, n, m);
    printf("Pozicija poslednjeg pojavljivanja: %d\n", i);
  } else
    printf("Nadmorska visina %d se ne nalazi medju podacima.\n", m);

  exit(EXIT_SUCCESS);
}
