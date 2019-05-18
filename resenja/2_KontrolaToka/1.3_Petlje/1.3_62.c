#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n;
  int i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Brojac i je redni broj vrste koja se ispisuje. */
  for (i = 1; i <= n; i++) {
    /* Ispis brojeva izmedju 1 i n, sa korakom i. */
    for (j = 1; j <= n; j += i)
      printf("%d ", j);

    printf("\n");
  }

  return 0;
}
