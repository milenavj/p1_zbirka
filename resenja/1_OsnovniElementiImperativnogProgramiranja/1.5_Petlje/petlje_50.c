#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Iscrtavanje znaka plus ispisom karaktera '+' na sredisnjoj
     vrsti i koloni, a blanko karaktera na ostalim mestima. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      if (i == n / 2 || j == n / 2)
        printf("+");
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}
