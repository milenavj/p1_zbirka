#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, i;
  long int clan, suma = 0;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */  
  if (n < 5 || n % 2 == 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Izracunava se trazena suma. */
  clan = -1 * 3;
  for (i = 5; i <= n; i += 2) {
    clan = -1 * clan * i;
    suma += clan;
  }

  /* Ispis rezultata. */
  printf("S = %ld\n", suma);

  return 0;
}
