#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  for (i = 1; i <= n; i++) {
    for (j = 1; j <= n; j++)
      if (j % i == 1 || i == 1)
        printf("%d ", j);

    printf("\n");
  }

  return 0;
}
