#include <stdio.h>

int main()
{
  char op;
  int x, y;

  printf("Unesite operator i dva cela broja: ");
  scanf("%c %d %d", &op, &x, &y);

  switch (op) {
  case '+':
    printf("Rezultat je: %d\n", x + y);
    break;
  case '-':
    printf("Rezultat je: %d\n", x - y);
    break;
  case '*':
    printf("Rezultat je: %d\n", x * y);
    break;
  case '/':
    if (y == 0)
      printf("Greska: deljenje nulom nije dozvoljeno!\n");
    else
      printf("Rezultat je: %f\n", x * 1.0 / y);
    break;
  case '%':
    printf("Rezultat je: %d\n", x % y);
    break;
  default:
    printf("Greska: nepoznat operator!\n");
  }

  return 0;
}
