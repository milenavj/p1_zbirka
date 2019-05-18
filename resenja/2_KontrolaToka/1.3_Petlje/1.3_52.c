#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Veliko slovo X se dobija tako sto se na dijagonalama kvadrata
     ispisuju zvezdice, a na ostalim mestima blanko. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      /* Provera da li je mesto glavne ili sporedne dijagonale. */
      if (i == j || i + j == n - 1)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}
