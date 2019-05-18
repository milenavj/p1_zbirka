#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  float cena, min_cena;

  /* Ucitavanje broja artikala. */
  printf("Unesite broj artikala:");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  printf("Unesite cene artikala:");

  /* Inicijalizacija minimalne cene na vrednost cenu prvog artikla.
     Zbog toga se cena prvog artikla ucitava pre petlje. */
  scanf("%f", &cena);
  if (cena <= 0) {
    printf("Greska: neispravan unos cene.\n");
    return -1;
  }
  min_cena = cena;

  /* Ucitavanje i preostalih n-1 cena i racunanje najmanje. */
  for (i = 1; i < n; i++) {
    scanf("%f", &cena);

    if (cena <= 0) {
      printf("Greska: neispravan unos cene.\n");
      return -1;
    }

    if (cena < min_cena)
      min_cena = cena;
    i++;
  }

  /* Ispis rezultata. */
  printf("Najmanja cena: %f\n", min_cena);

  return 0;
}
