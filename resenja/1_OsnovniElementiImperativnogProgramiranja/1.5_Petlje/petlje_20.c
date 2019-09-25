#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float cena, m;
  unsigned int n, i, broj_artikala = 0;

  /* Ucitavanje vrednosti broja m. */
  printf("Nikolin budzet: ");
  scanf("%f", &m);

  /* Ucitavanje broja artikala. */
  printf("Unesite broj artikala: ");
  scanf("%u", &n);

  /* Ucitavanje cena artikala i racunanje rezultata. */
  printf("Unesite cene artikala: ");
  for (i = 0; i < n; i++) {
    /* Ucitavanje cene artikla. */
    scanf("%f", &cena);

    /* Provera da li Nikola moze da kupi trenutni artikal. */
    if (cena <= m)
      broj_artikala++;
  }

  /* Ispis rezultata. */
  printf("Ukupno artikala: %d\n", broj_artikala);

  return 0;
}
