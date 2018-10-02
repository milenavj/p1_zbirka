#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b, max;
  
  /* Ucitavaju se dve celobrojne vrednosti. */
  printf("Unesite dva cela broja:");
  scanf("%d%d", &a, &b);

  /* Racuna se maksimum koriscenjem ternarnog operatora uslova. */
  max = (a > b) ? a : b;

  /* Ispis rezultata. */
  printf("Maksimum je %d\n", max);

  return 0;
}
