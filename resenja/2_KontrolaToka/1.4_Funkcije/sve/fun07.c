#include <stdio.h>

/* Funkcija broji koliko puta se realan broj x javlja u nizu unetih
   brojeva. */
int prebrojavanje(float x) {
  float y;
  int broj_pojavljivanja = 0;

  /* Brojevi se ucitavaju sve do unosa broja nula. Svaki put kada
     se unese broj koji je jednak broju x, brojac pojavljivanja se
     uveca za 1. */
  printf("Unesite brojeve:\n");
  while (1) {
    scanf("%f", &y);

    if (y == 0)
      break;

    if (x == y)
      broj_pojavljivanja++;
  }

  return broj_pojavljivanja;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float x;
  int rezultat;

  /* Ucitavanje vrednosti broja x. */
  printf("Unesite broj x: ");
  scanf("%f", &x);

  /* Ucitavanje brojeva i racunanje rezultata. */
  rezultat = prebrojavanje(x);

  /* Ispis rezultata. */
  printf("Broj pojavljivanja broja %.2f: %d\n", x, rezultat);

  return 0;
}
