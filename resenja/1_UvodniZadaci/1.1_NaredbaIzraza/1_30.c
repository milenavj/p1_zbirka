#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b, max;
  
  /* Ucitavanje dve celobrojne vrednosti. */
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &a, &b);

  /* Racunanje maksimuma koriscenjem ternarnog operatora. */
  max = (a > b) ? a : b;

  /* Ispis rezultata. */
  printf("Maksimum je %d\n", max);

  return 0;
}
