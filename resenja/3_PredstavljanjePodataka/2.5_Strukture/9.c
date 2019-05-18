#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS 50

typedef struct {
  int poluprecnik;
  enum { plava, zuta, crvena, zelena } boja;
} Lopta;

/* Funkcija racuna zapreminu lopte. */
float zapremina(const Lopta *l) {
  return pow(l->poluprecnik, 3) * 4 / 3 * M_PI;
}

/* Funkcija racuna zbir zapremina svih lopti u nizu. */
float ukupna_zapremina(Lopta lopte[], int n) {
  int i;
  float ukupno = 0;

  for (i = 0; i < n; i++)
    ukupno += zapremina(&lopte[i]);

  return ukupno;
}

/* Funkcija broji lopte cija je boja jednaka boji koja je
   prosledjena kao argument funkcije. */
int broj_lopti_u_boji(Lopta lopte[], int n, unsigned boja) {
  int brojac = 0, i;

  for (i = 0; i < n; i++)
    if (lopte[i].boja == boja)
      brojac++;

  return brojac;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  Lopta lopte[MAKS];
  int i, n;
  unsigned boja;

  /* Ucitavanje broja lopti i provera ispravnosti ulaza. */
  printf("Unesite broj lopti: ");
  scanf("%d", &n);
  if (n < 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje lopti u niz. */
  printf("Unesite dalje poluprecnike i boje lopti "
         "(1-plava, 2-zuta, 3-crvena, 4-zelena):\n");
  for (i = 0; i < n; i++) {
    printf("%d. lopta: ", i + 1);
    scanf("%d%u", &lopte[i].poluprecnik, &boja);
    if (boja < 1 || boja > 4) {
      printf("Greska: neispravan unos.\n");
      exit(EXIT_FAILURE);
    }
    lopte[i].boja = boja;
  }

  /* Ispis rezultata. */
  printf("Ukupna zapremina: %.2f\n", ukupna_zapremina(lopte, n));
  printf("Ukupno crvenih lopti: %d\n",
         broj_lopti_u_boji(lopte, n, crvena));

  return 0;
}
