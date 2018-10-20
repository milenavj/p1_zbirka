#include <stdio.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  double clan, proizvod = 1;

  /* Ucitava se vrednost broja n i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Racuna se trazeni proizvod. */
  clan = 1;
  for (i = 2; i <= n; i++) {
    clan = clan / i;
    proizvod *= 1 + clan;
  }

  /* Ispis rezultata. */
  printf("P = %lf\n", proizvod);

  return 0;
}
