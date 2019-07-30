#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main() {
  /* Deklaracija potrebnih promenljivih. */
  float brojevi[MAKS];
  int n, i;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  printf("Unesite elemente niza:\n");
  for (i = 0; i < n; i++)
    scanf("%f", &brojevi[i]);

  /* Ukoliko je i-ti element niza brojevi[i] negativan broj,
     kvadrira se tako sto se pomnozi samim sobom. */
  for (i = 0; i < n; i++)
    if (brojevi[i] < 0)
      brojevi[i] *= brojevi[i];

  /* Ispis novodobijenog niza. */
  printf("Rezultujuci niz: ");
  for (i = 0; i < n; i++)
    printf("%g ", brojevi[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
