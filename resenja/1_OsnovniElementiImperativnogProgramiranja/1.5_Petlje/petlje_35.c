#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, i, suma_kubova;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n:");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Racunanje sume kubova svih brojeva iz intervala [1,n]. */
  suma_kubova = 0;
  for (i = 1; i <= n; i++)
    suma_kubova += i * i * i;

  /* Ispis rezultata. */
  printf("Suma kubova: %d\n", suma_kubova);

  return 0;
}
