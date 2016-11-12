#include <stdio.h>

int main()
{
  int n, i, znak = -1;
  /* Promenljiva clan je deo proizvoda i predstavlja 1*3*5*...*i. */
  long int clan;
  long int S = 0;

  printf("Unesite prirodan broj: ");
  scanf("%d", &n);

  if (n < 5 || n % 2 == 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  clan = 1 * 3;
  for (i = 5; i <= n; i += 2) {
    clan = znak * clan * i;
    S += clan;
  }

  printf("S = %ld\n", S);

  return 0;
}
