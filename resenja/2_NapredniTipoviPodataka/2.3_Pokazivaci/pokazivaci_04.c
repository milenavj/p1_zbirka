#include <stdio.h>
#include <stdlib.h>

/* Funkcija racuna kolicnik i ostatak pri deljenju a sa b.
   Ukoliko su ove vrednosti uspesno izracunate, funkcija vraca 1, a 
   inace vraca nulu. */
int kolicnik_ostatak(int a, int b, int *pkolicnik, int *postatak) {
  if (b == 0)
    return 0;

  *pkolicnik = a / b;
  *postatak = a % b;
  return 1;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b, kolicnik, ostatak;

  /* Ucitavanje vrednosti a i b. */
  printf("Unesite brojeve: ");
  scanf("%d%d", &a, &b);

  /* Ispis rezultata. */
  if (kolicnik_ostatak(a, b, &kolicnik, &ostatak)) {
    printf("Kolicnik: %d\n", kolicnik);
    printf("Ostatak: %d\n", ostatak);
  } else {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
