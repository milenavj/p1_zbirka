#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Iscrtava se trazeni trougao. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
