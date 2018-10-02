#include <stdio.h>

int main()
{
  int n;
  float x;
  float vrednost;
  unsigned exp;

  printf("Unesite redom brojeve x i n: ");
  scanf("%f %d", &x, &n);

  if (n < 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  /* Pocetna vrednost stepena koji se racuna.  */
  vrednost = 1;

  for (exp = 1; exp <= n; exp++)
    vrednost = vrednost * x;

  printf("%f\n", vrednost);

  return 0;
}
