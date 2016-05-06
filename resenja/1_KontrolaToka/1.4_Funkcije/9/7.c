#include <stdio.h>

/* Funkcija broji koliko puta se realan broj x
 * javlja u nizu unetih brojeva sa tastature.
 * 
 * Brojevi se unose sve do pojave 0,
 * pa treba koristiti do..while petlju,
 * kako bi bar jedan broj bio unet (makar bio i 0).
 */
int prebrojavanje(float x) {
  
  /* y prihvata uneti broj sa tastature */
  float y;
  /* br_pojavljivanja je brojac koji broji koliko puta se broj x javlja u unetom nizu brojeva */
  int br_pojavljivanja = 0;

  printf("Unesite brojeve: ");
  do {

    /* Unosimo broj. */
    scanf("%f", &y);

    /* Poredimo uneti broj sa datim brojem.
     * Ukoliko je unet bas trazeni broj,
     * uvecavamo brojac.
     * */
    if(x == y)
      br_pojavljivanja++;

  } while(y); /* Sve dok nije uneta 0 */

  return br_pojavljivanja;
}

int main() {
  
  float x;
  int br_pojavljivanja;

  printf("Unesite broj x: ");
  scanf("%f", &x);

  br_pojavljivanja = prebrojavanje(x);
  printf("Broj pojavljivanja broja %.2f je: %d\n", x, br_pojavljivanja);

  return 0;
}