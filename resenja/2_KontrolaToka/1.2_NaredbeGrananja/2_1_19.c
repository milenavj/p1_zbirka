#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a1, a2, b1, b2;

  /* Ucitavaju se granice intervala. */
  printf("Unesite a1, b1, a2 i b2: ");
  scanf("%d%d%d%d", &a1, &b1, &a2, &b2);

  /* U zavisnosti od razlicitih polozaja dva intervala, racunaju se 
     i ispisuju trazene vrednosti. */
  if (a1 <= a2 && b1 >= a2) {
    /* I slucaj: intervali se seku i [a1,b1] je pre [a2,b2]. */
    printf("Duzina preseka:: %d\n", b1 - a2);
    printf("Presecni interval: [%d, %d]\n", a2, b1);
    printf("Duzina koju pokrivaju: %d\n", b2 - a1);
    printf("Najmanji interval: [%d, %d]\n", a1, b2);
  } else if (a2 <= a1 && b2 >= a1) {
    /* II slucaj: intervali se seku i [a2,b2] je pre [a1,b1]. */
    printf("Duzina preseka:: %d\n", b2 - a1);
    printf("Presecni interval: [%d, %d]\n", a1, b2);
    printf("Duzina koju pokrivaju: %d\n", b1 - a2);
    printf("Najmanji interval: [%d, %d]\n", a2, b1);
  } else if (a1 >= a2 && b1 <= b2) {
    /* III slucaj: interval [a1,b1] se nalazi unutar [a2,b2]. */
    printf("Duzina preseka:: %d\n", b1 - a1);
    printf("Presecni interval: [%d, %d]\n", a1, b1);
    printf("Duzina koju pokrivaju: %d\n", b2 - a2);
    printf("Najmanji interval: [%d, %d]\n", a2, b2);
  } else if (a2 >= a1 && b2 <= b1) {
    /* IV slucaj: interval [a2,b2] se nalazi unutar [a1,b1]. */
    printf("Duzina preseka:: %d\n", b2 - a2);
    printf("Presecni interval: [%d, %d]\n", a2, b2);
    printf("Duzina koju pokrivaju: %d\n", b1 - a1);
    printf("Najmanji interval: [%d, %d]\n", a1, b1);
  } else {
    /* V slucaj: intervali su disjunktni. */
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
