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

/* Funkcija racuna broj elemenata niza koji su manji od poslednjeg
   elementa. */
int prebrojavanje(int a[], int n) {
  int i, broj_manjih = 0;

  /* Prebrojavaju se elementi niza za koje vazi da su manji od
     poslednjeg elementa (a[n-1]). Petlja ide od prvog do
     predposlednjeg elementa. */
  for (i = 0; i < n - 1; i++)
    if (a[i] < a[n - 1])
      broj_manjih++;

  return broj_manjih;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
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

  /* Ispis rezultata. */
  printf("Rezultat: %d\n", prebrojavanje(a, n));

  exit(EXIT_SUCCESS);
}
