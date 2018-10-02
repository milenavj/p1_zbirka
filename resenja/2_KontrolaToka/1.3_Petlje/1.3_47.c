#include <stdio.h>

int main()
{
  int n, i;
  /* Promenljiva clan je deo proizvoda i predstavlja 1/i!. */
  double clan;
  double S = 1;

  printf("Unesite prirodan broj: ");
  scanf("%d", &n);

  if (n <= 1) {
    printf("Neispravan unos.\n");
    return -1;
  }

  clan = 1;
  for (i = 2; i <= n; i++) {
    clan = clan / i;
    S *= 1 + clan;
  }

  printf("S = %lf\n", S);

  return 0;
}
