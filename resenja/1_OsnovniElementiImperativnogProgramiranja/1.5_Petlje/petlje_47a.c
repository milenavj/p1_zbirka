#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Ispis tablice mnozenja dimenzije n*n. */
  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++) {
      /* Vrednost svakog polja je proizvod vrste i kolone. */
      printf("%3d ", i * j);
    }
    /* Na kraju svake vrste se ispisuje novi red. */
    printf("\n");
  }

  return 0;
}
