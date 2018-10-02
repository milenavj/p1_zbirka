#include <stdio.h>

int main()
{
  int n, i;
  float x, S, stepen;

  printf("Unesite redom brojeve x i n: ");
  scanf("%f %d", &x, &n);

  if (n < 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  /* Inicijalizacija sume. */
  S = 0;

  /* Stepen promenljiva ce sadrzati vrednosti stepena x^n. Pocetna
     vrednost joj je 1 jer je x^0 = 1. */
  stepen = 1;

  for (i = 1; i <= n; i++) {
    stepen = stepen * x;
    S = S + i * stepen;
  }

  printf("S=%f\n", S);

  return 0;
}
