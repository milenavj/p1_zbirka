#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Ispis trazenog trougla. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++)
      printf("(%d, %d)", i, j);

    printf("\n");
  }

  return 0;
}
