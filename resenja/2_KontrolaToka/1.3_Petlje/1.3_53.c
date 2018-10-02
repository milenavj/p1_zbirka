#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  if (n % 2 == 0) {
    printf("Pogresan unos.\n");
    return -1;
  }

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
