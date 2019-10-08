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
  int a_n;

  /* Ucitavanje vrednosti prvog clana. */
  printf("Unesite prvi clan:");
  scanf("%d", &a_n);

  /* Provera ispravnosti ulaza. */
  if (a_n <= 0) {
    printf("Greska: neispravan unos.\n");
    return 1;
  }

  /* Dok se ne dodje do clana koji je 1, stampa se vrednost
     trenutnog clana i vrsi se izracunavanje narednog, po zadatoj
     formuli. */
  printf("Clanovi niza su:\n");
  while (a_n != 1) {
    printf("%d ", a_n);

    if (a_n % 2 != 0)
      a_n = (3 * a_n + 1) / 2;
    else
      a_n = a_n / 2;
  }

  /* Ispis jedinice na kraju. */
  printf("1\n");

  return 0;
}
