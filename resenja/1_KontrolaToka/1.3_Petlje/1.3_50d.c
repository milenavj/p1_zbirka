#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  for (i = 0; i < n; i++) {
    for (j = 0; j < n - i; j++)
      printf("(%d, %d)", i, j);

    printf("\n");
  }

  return 0;
}
