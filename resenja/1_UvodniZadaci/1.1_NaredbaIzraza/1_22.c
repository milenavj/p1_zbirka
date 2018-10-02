#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float r, O, P;

  /* Ucitava se poluprecnik kruga. */
  printf("Unesite duzinu poluprecnika kruga:");
  scanf("%f", &r);

  /* Racunaju se obim i povrsina.
     M_PI je konstanta koja se nalazi u zaglavlju math.h
     i njena vrednost odgovara vrednosti broja pi. */
  O = 2 * r * M_PI;
  P = r * r * M_PI;

  /*Ispis rezultata na dve decimale. */
  printf("Obim: %.2f\nPovrsina: %.2f\n", O, P);

  return 0;
}
