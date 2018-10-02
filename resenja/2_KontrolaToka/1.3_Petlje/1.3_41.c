#include <stdio.h>

int main()
{
  unsigned n, i;
  float x, S, stepen;

  printf("Unesite redom brojeve x i n: ");
  scanf("%f %u", &x, &n);

  S = 1;
  stepen = 1;
  for (i = 1; i <= n; i++) {
    stepen = stepen * x;
    S = S + 1 / stepen;
  }

  printf("S=%f\n", S);

  return 0;
}
