#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, x, i;
  int zbir = 0;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Ucitavanje brojeva i racunanje trazenog zbira. */
  printf("Unesite n brojeva: ");
  i = 0;
  while (i < n) {
    /* Ucitavanje jednog broja. */
    scanf("%d", &x);

    /* Ako je ucitani broj negativan i neparan, dodaje se na 
       zbir. */
    if (x < 0 && x % 2 != 0)
      zbir = zbir + x;

    /* Uvecavanje brojaca. */
    i++;
  }

  /* Ispis rezultata. */
  printf("Zbir neparnih i negativnih: %d\n", zbir);

  return 0;
}
