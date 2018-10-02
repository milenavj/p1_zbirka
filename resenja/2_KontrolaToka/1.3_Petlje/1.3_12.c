#include<stdio.h>

int main()
{
  int n;
  /* Oznaka broja koji unosimo u jednoj iteraciji petlje. */
  int x;
  int suma_poz;
  int suma_neg;
  /* Brojac. */
  int i;

  printf("Unesi pozitivan ceo broj:");
  scanf("%d", &n);

  if (n < 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  /* Promenljivama koje ce sadrzati sume se pre ulaska u petlju
     dodeljuje 0 (neutral za sabiranje). */
  suma_poz = 0;
  suma_neg = 0;
  i = 0;

  printf("Unesite brojeve: ");
  while (i < n) {
    scanf("%d", &x);

    if (x < 0)
      suma_neg += x;
    else
      suma_poz += x;

    i++;
  }

  printf(" Suma pozitivnih: %d\n Suma negativnih: %d\n", suma_poz,
         suma_neg);
  return 0;
}
