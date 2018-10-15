#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char op;
  int x, y;

  /* Ucitava se izraz. */
  printf("Unesite izraz: ");
  scanf("%d %c %d", &x, &op, &y);

  /* U zavisnosti od unete operacije, racuna se vrednost izraza. */
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
      printf("Greska: deljenje nulom.\n");
    else
      printf("Rezultat je: %d\n", x / y);
    break;
  case '%':
    printf("Rezultat je: %d\n", x % y);
    break;
  default:
    printf("Greska: nepoznat operator.\n");
  }

  return 0;
}
