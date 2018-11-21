#include <stdio.h>
#include <math.h>

/* Funkcija vraca razlomljeni deo prosledjenog broja. */
float razlomljeni_deo(float x)
{
  /* Napomena: Funkcija fabs racuna apsolutnu vrednost realnog
     broja i njena deklaracija se nalazi u zaglavlju math.h.
     Funkcija abs racuna apsolutnu vrednost celog broja i njena
     deklaracija se nalazi u zaglavlju stdlib.h. */
  x = fabs(x);

  /* Razlomljeni deo broja se dobija tako sto se od samog broja
     oduzme njegov ceo deo. */
  return x - (int) x;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float n;

  /* Ucitava se ulazna vrednost. */
  printf("Unesite broj:");
  scanf("%f", &n);

  /* Ispis rezultata. */
  printf("Razlomljeni deo: %.6f\n", razlomljeni_deo(n));

  return 0;
}
