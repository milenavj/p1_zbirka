#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int i, n;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: pogresan unos broja n.\n");
    return 1;
  }

  /* Inicijalizacija brojaca. */
  i = 0;

  /* Trazena poruka se ispisuje n puta. */
  while (i < n) {
    printf("Mi volimo da programiramo.\n");
    i++;
  }

  return 0;
}
