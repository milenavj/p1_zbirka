#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float a, b, rezultat;
  float min, max;
  
  /* Ucitavanje vrednosti dva realna broja. */
  printf("Unesite dva realna broja: ");
  scanf("%f%f", &a, &b);

  /* Racunanje minimalne i maksimalne vrednost unetih brojeva. */
  min = (a < b) ? a : b;
  max = (a > b) ? a : b;

  /* Racunanje rezultata. */
  rezultat = (min + 0.5) / (1 + max * max);

  /* Ispis rezultata. */
  printf("Rezultat je %.2f\n", rezultat);

  return 0;
}
