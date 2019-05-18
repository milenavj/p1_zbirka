#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char op;
  int x, y;

  /* Ucitavanje izraza. */
  printf("Unesite izraz: ");
  scanf("%d %c %d", &x, &op, &y);

  /* Racunanje vrednosti izraza u zavisnosti od unete operacije. */
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
