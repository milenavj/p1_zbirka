#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float r, obim, povrsina;

  /* Ucitava se poluprecnik kruga. */
  printf("Unesite poluprecnik: ");
  scanf("%f", &r);

  /* Racunaju se obim i povrsina.
     M_PI je konstanta koja se nalazi u zaglavlju math.h
     i njena vrednost odgovara vrednosti broja pi. */
  obim = 2 * r * M_PI;
  povrsina = r * r * M_PI;

  /*Ispis rezultata na dve decimale. */
  printf("Obim: %.2f\nPovrsina: %.2f\n", obim, povrsina);

  return 0;
}
