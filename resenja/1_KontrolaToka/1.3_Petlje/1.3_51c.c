#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  for (i = 0; i < n; i++) {
    /* Kvadrat predstavlja tabelu sa n vrsta gde su ivice karakter
       *, a unutrasnjost kvadrata je karakter blanko osim na
       mestima na kojima je glavna dijagonala. */
    for (j = 0; j < n; j++)
      /* Provera da li je ivica ili glavna dijagonala. */
      if (j == 0 || j == n - 1 || i == 0 || i == n - 1 || i == j)
        printf("*");
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}