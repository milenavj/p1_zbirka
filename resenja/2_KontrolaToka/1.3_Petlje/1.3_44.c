#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  double x, x_i, proizvod;

  /* Ucitavanje i provera ispravnosti ulaza. */
  printf("Unesite redom brojeve x i n: ");
  scanf("%lf %d", &x, &n);

  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Racuna se trazeni proizvod. */
  x_i = 1;
  proizvod = 1;
  for (i = 0; i < n; i++) {
    x_i *= x;
    proizvod *= 1 + cos(x_i);
  }
  
  /* Ispis rezultata. */
  printf("P = %lf\n", proizvod);

  return 0;
}
