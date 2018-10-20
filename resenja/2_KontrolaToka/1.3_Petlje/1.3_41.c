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

  /* Racuna se trazena suma. */
  suma = 1;
  x_i = x;
  for (i = 1; i <= n; i++) {
    suma += 1 / x_i;
    x_i *= x;
  }

  /* Ispis rezultata. */
  printf("S=%f\n", suma);

  return 0;
}
