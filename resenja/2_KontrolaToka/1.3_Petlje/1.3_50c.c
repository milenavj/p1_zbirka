#include <stdio.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);
  
  /* Ispis trazene tablice. */
  for (i = 1; i <= n; i++) {
    for (j = 0; j < n; j++)
      if ((j + i) % n == 0)
        printf("%3d", n);
      else
        printf("%3d", (j + i) % n);

    printf("\n");
  }

  return 0;
}
