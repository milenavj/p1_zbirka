#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, broj, i;
  int suma = 0;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Ucitavanje n brojeva i racunanje trazene sume. */
  printf("Unesite brojeve: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &broj);

    if (broj % 5 == 0 && broj % 7 != 0)
      suma += broj;
  }

  /* Ispis rezultata. */
  printf("Suma je %d.\n", suma);

  return 0;
}
