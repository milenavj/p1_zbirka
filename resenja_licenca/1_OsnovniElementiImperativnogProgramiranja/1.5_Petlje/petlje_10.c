/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  int x;

  /* Ucitavanje vrednosti broja x. */
  printf("Unesite ceo broj:");
  scanf("%d", &x);

  /* Izracunava se apsolutna vrednost broja da bi izdvojene cifre bile
     pozitivni brojevi. Na primer, 123%10 je 3, a -123%10 je -3. */
  x = abs(x);

  /* Slucaj kada je uneti broj 0 se posebno obradjuje. */
  if (x == 0) {
    printf("0\n");
    return 0;
  }

  /* U petlji se obradjuje cifra po cifra broja, dok god ima
     neobradjenih cifara u broju. */
  printf("Rezultat: ");
  while (x != 0) {
    /* Ispis poslednje cifre broja x. */
    printf("%d ", x % 10);

    /* Uklanjanje poslednje cifre broja x. */
    x /= 10;
  }
  printf("\n");

  return 0;
}
