#include<stdio.h>
#include<math.h>

/* Funkcija koja vraca razlomljeni deo prosledjenog broja. */
float razlomljeni_deo(float x){

  /* Funkcija fabs vraca apsolutnu vrednost realnog broja.
   * NAPOMENA: funkcija fabs se nalazi u zaglavlju math.h.
   * NAPOMENA2: funkcija abs se nalazi u zaglavlju stdlib.h, ali se koristi samo za cele brojeve!
  */
  x = fabs(x);
  
  /* Razlomljeni deo broja se dobija tako sto od samog broja se oduzme njegov ceo deo. */
  return x - (int)x;
}

int main() {
  float n;
  
  /* Unos broja. */
  printf("Unesite broj:");
  scanf("%f", &n);
  
  /* Ispis rezultata. */
  printf("Razlomljeni deo: %.6f\n", razlomljeni_deo(n));
  
  return 0;
}
