#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, x, i;
  int zbir = 0;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Ucitava se n brojeva i izracunava se trazeni zbir. */
  printf("Unesite n brojeva: ");
  i = 0;
  while (i < n) {
    /* Ucitava se jedan broj. */
    scanf("%d", &x);

    /* Ako je ucitani broj negativan i neparan, 
       dodaje se na zbir. */
    if (x < 0 && x % 2 != 0)
      zbir = zbir + x;

    /* Uvecava se brojac. */
    i++;
  }

  /* Ispis rezultata. */
  printf("Zbir neparnih i negativnih: %d\n", zbir);

  return 0;
}
