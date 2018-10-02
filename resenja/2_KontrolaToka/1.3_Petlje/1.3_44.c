#include <stdio.h>
#include <math.h>

int main()
{
  int n, i;
  double x;
  double stepen = 1;
  double proizvod = 1;

  printf("Unesite redom brojeve x i n: ");
  scanf("%lf %d", &x, &n);

  if (n <= 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  for (i = 0; i < n; i++) {
    stepen *= x;
    proizvod *= 1 + cos(stepen);
  }

  printf("Proizvod = %lf\n", proizvod);

  return 0;
}
