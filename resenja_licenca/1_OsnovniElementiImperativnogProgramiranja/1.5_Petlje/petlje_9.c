/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  int n;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Slucaj kada broj n ima vrednost nula se posebno obradjuje.
     U suprotnom bi se petlja u nastavku beskonacno izvrsavala. */
  if (n == 0) {
    printf("0\n");
    return 0;
  }

  /* Uklanjanje poslednje cifre broja se vrsi deljenjem broja sa 10.
     Ovaj postupak se ponavlja sve dok je poslednja cifra nula. */
  while (n % 10 == 0)
    n = n / 10;

  /* Ispis rezultata. */
  printf("Rezultat: %d\n", n);

  return 0;
}
