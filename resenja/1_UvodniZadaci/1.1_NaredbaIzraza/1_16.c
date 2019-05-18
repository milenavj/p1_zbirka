#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  float in, cm;

  /* Ucitavanje realnog broja koji predstavlja broj inca. */
  printf("Unesite broj inca: ");
  scanf("%f", &in);

  /* Racunanje rezultata (1 in = 2.54 cm) */
  cm = in * 2.54;

  /* Ispis rezultata (na dve decimale). */
  printf("%.2f in = %.2f cm\n", in, cm);

  return 0;
}
