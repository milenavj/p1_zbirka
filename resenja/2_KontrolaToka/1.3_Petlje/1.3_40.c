#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, i;
  float x, suma, x_i;

  /* Ucitavanje i provera ispravnosti ulaza. */
  printf("Unesite redom brojeve x i n: ");
  scanf("%f %d", &x, &n);

  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Vrednost sume se inicijalizuje na nulu, a vrednost x^i
     na x. */
  suma = 0;
  x_i = x;

  /* Promenljiva x^i ima vrednosti [x, x^2, ..., x^n]. 
     Vrednost sume se u svakoj iteraciji uvecava za i*x^i. */
  for (i = 1; i <= n; i++) {
    suma += i * x_i;
    x_i *= x;
  }

  /* Ispis rezultata. */
  printf("S=%f\n", suma);

  return 0;
}
