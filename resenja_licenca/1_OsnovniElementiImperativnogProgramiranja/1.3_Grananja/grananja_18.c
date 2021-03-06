/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a1, a2, b1, b2;

  /* Ucitavanje granica intervala. */
  printf("Unesite a1, b1, a2 i b2: ");
  scanf("%d%d%d%d", &a1, &b1, &a2, &b2);

  /* Racunanje i ispis trazenih vrednosti (u zavisnosti od 
     razlicitih polozaja dva intervala). */
  if (a1 <= a2 && b1 >= a2) {
    /* I slucaj: Intervali se seku i [a1,b1] je pre [a2,b2]. */
    printf("Duzina preseka:: %d\n", b1 - a2);
    printf("Presecni interval: [%d, %d]\n", a2, b1);
    printf("Duzina koju pokrivaju: %d\n", b2 - a1);
    printf("Najmanji interval: [%d, %d]\n", a1, b2);
  } else if (a2 <= a1 && b2 >= a1) {
    /* II slucaj: Intervali se seku i [a2,b2] je pre [a1,b1]. */
    printf("Duzina preseka:: %d\n", b2 - a1);
    printf("Presecni interval: [%d, %d]\n", a1, b2);
    printf("Duzina koju pokrivaju: %d\n", b1 - a2);
    printf("Najmanji interval: [%d, %d]\n", a2, b1);
  } else if (a1 >= a2 && b1 <= b2) {
    /* III slucaj: Interval [a1,b1] se nalazi unutar [a2,b2]. */
    printf("Duzina preseka:: %d\n", b1 - a1);
    printf("Presecni interval: [%d, %d]\n", a1, b1);
    printf("Duzina koju pokrivaju: %d\n", b2 - a2);
    printf("Najmanji interval: [%d, %d]\n", a2, b2);
  } else if (a2 >= a1 && b2 <= b1) {
    /* IV slucaj: Interval [a2,b2] se nalazi unutar [a1,b1]. */
    printf("Duzina preseka:: %d\n", b2 - a2);
    printf("Presecni interval: [%d, %d]\n", a2, b2);
    printf("Duzina koju pokrivaju: %d\n", b1 - a1);
    printf("Najmanji interval: [%d, %d]\n", a1, b1);
  } else {
    /* V slucaj: Intervali su disjunktni. */
    printf("Duzina preseka:: 0\n");
    printf("Presecni interval: prazan\n");
    printf("Duzina koju pokrivaju: %d\n", b1 - a1 + b2 - a2);
    if (a1 < a2)
      printf("Najmanji interval: [%d, %d]\n", a1, b2);
    else
      printf("Najmanji interval: [%d, %d]\n", a2, b1);
  }

  return 0;
}
