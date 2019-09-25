#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  float x, apsolutno_x;

  /* Ucitavanje vrednosti broja. */
  printf("Unesite jedan realan broj:");
  scanf("%f", &x);

  /* Racunanje apsolutne vrednosti unetog broja. */
  apsolutno_x = x;
  if (x < 0)
    apsolutno_x = -x;

  /* Ispis rezultata. */
  printf("Apsolutna vrednost: %.2f\n", apsolutno_x);

  /* II nacin: koriscenjem funkcije fabs cija se deklaracija nalazi 
     u zaglavlju math.h: apsolutno_x=fabs(x); */

  return 0;
}
