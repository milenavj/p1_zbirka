#include <stdio.h>

int main() {
  /* Deklaracija i inicijalizacije potrebnih promenljivih. */
  int x, broj_brojeva = 0, suma = 0;

  /* Ucitavanje brojeva sve do unosa broja 0. */
  printf("Unesite brojeve: ");
  while (1) {
    scanf("%d", &x);

    if (x == 0)
      break;

    /* Dodavanje ucitanog broja na sumu. */
    suma += x;

    /* Uvecavanje broja ucitanih brojeva. */
    broj_brojeva++;
  }

  /* Ispis rezultata. Napomena: I suma i broj brojeva su celi
     brojevi pa je neophodno bar jednu od te dve vrednosti pretvoriti
     u realan broj kako deljenje ne bi bilo celobrojno. */
  if (broj_brojeva == 0)
    printf("Nisu uneti brojevi.\n");
  else
    printf("Aritmeticka sredina: %.4f\n",
           (double) suma / broj_brojeva);

  return 0;
}
