#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Kvadrat predstavlja tabelu sa n vrsta i n kolona u kojoj se
     na ivicama nalaze zvezdice, a u unutrasnjosti praznine. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      /* Provera da li je u pitanju ivica. */
      if (j == 0 || j == n - 1 || i == 0 || i == n - 1)
        printf("*");
      else
        printf(" ");
    }
    printf("\n");
  }

  return 0;
}
