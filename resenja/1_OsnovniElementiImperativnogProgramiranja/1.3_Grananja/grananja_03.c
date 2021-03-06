#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int x;
  float reciprocno_x;

  /* Ucitavanje vrednosti broja x. */
  printf("Unesite jedan ceo broj:");
  scanf("%d", &x);

  /* Provera ispravnosti ulaznih podataka. Napomena: Za
     razliku od izlaza iz programa sa kodom 0 (return 0;) koji
     sluzi kao indikator da se program zavrsio uspesno, izlaz iz
     programa sa izlaznim kodom razlicitim od nule sluzi kao
     indikator da je pri izvrsavanju programa doslo do neke greske. */
  if (x == 0) {
    printf("Greska: nedozvoljeno je deljenje nulom.\n");
    return 1;
  }

  /* Racunanje reciprocne vrednosti. */
  reciprocno_x = 1.0 / x;

  /* Ispis rezultata. */
  printf("Reciprocna vrednost: %.4f\n", reciprocno_x);

  return 0;
}
