#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Iscrtavanje trazenog trougla. */
  for (i = 0; i < n; i++) {
    /* Ispis belina koje prethode zvezdicama. */
    for (j = 0; j < i; j++)
      printf(" ");
    /* Ispis potrebnog broja zvezdica. */
    for (j = 0; j < n - i; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
