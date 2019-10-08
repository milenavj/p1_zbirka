/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

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
