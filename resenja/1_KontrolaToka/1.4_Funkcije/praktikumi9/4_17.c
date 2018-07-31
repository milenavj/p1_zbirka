#include <stdio.h>

/* Funkcija broji koliko puta se realan broj x javlja u nizu unetih brojeva. */
int prebrojavanje(float x) {
  
  float y;
  /* Promenljiva br_pojavljivanja je brojac koji broji koliko puta se broj x javlja u unetom nizu brojeva. */
  int br_pojavljivanja = 0;

  printf("Unesite brojeve: ");
  do {

    /* Unos broja. */
    scanf("%f", &y);

    /* Poredjenje unetog broja sa datim brojem. Ukoliko je unet jednak trazenom broju, brojac se uvecava. */
    if(x == y)
      br_pojavljivanja++;

  } while(y); 
  /* Brojevi se unose sve dok se ne unese 0. */

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
