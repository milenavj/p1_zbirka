#include<stdio.h>
#include<math.h>

/* Funkcija koja vraca razlomljeni deo prosledjenog broja */
float razlomljeni_deo(float x){

  /* Funkcija fabs vraca apsolutnu vrednost realnog broja
   * NAPOMENA: funkcija fabs se nalazi u zaglavlju math.h
   * NAPOMENA2: funkcija abs se nalazi u zaglavlju stdlib.h, ali se koristi samo za cele brojeve!
  */
  x = fabs(x);
  
  /* Razlomljeni deo broja dobijamo tako sto od samog broja oduzmemo njegov ceo deo*/
  return x - (int)x;
}

int main(){
  float n;
  
  /* Ucitavamo broj */
  printf("Unesite broj:");
  scanf("%f", &n);
  
  /* Ispisujemo rezultat */
  printf("Razlomljeni deo: %.6f\n", razlomljeni_deo(n));
  
  return 0;
}
