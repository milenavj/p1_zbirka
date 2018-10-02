#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, P, O;

  /* Ucitava se duzina stranice. */
  printf("Unesite duzinu stranice trougla:");
  scanf("%f", &a);

  /* Racuna se obim i povrsina. */
  O = 3 * a;
  P = (a * a * sqrt(3)) / 4;

  /* Ispis rezultata na dve decimale. */
  printf("Obim: %.2f\n", O);
  printf("Povrsina: %.2f\n", P);

  return 0;
}
