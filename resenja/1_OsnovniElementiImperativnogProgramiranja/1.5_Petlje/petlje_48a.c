#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Kvadrat predstavlja tabelu sa n vrsta gde svaka vrsta sadrzi n 
     polja i u svakom polju je upisana zvezdica. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
