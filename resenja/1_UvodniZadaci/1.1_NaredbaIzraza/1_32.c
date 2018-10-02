#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, b, rez;
  float min, max;
  
  /* Ucitavaju se dva realna broja. */
  printf("Unesite dva realna broja:");
  scanf("%f%f", &a, &b);

  /* Racunaju se minimalna i maksimalna vrednost unetih brojeva. */
  min = (a < b) ? a : b;
  max = (a > b) ? a : b;

  /* Racuna se vrednost rezultata. */
  rez = (min + 0.5) / (1 + max * max);

  /* Ispis rezultata. */
  printf("Rezultat je %.2f\n", rez);

  return 0;
}
