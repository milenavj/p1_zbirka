#include <stdio.h>

int main(void)
{
  int n, n_abs;
  float x;
  float vrednost;
  unsigned exp;

  printf("Unesite redom brojeve x i n: ");
  scanf("%f %d", &x, &n);

  /* Pocetna vrednost stepena koji se racuna. */
  vrednost = 1;

  /* Stepenovanje. */
  n_abs = abs(n);
  for (exp = 1; exp <= n_abs; exp++)
    vrednost = vrednost * x;

  /* Ukoliko je stepen bio negativan treba odrediti 1/x^n, sto je
     zapravo 1/vrednost. */
  if (n < 0) {
    printf("%.3f\n", 1 / vrednost);
  } else {
    printf("%.3f\n", vrednost);
  }

  return 0;
}
