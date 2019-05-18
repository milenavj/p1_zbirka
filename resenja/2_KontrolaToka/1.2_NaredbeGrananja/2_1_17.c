#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  float xa, ya, xb, yb;

  /* Ucitavanje koordinata tacaka A i B. */
  printf("Unesite koordinate tacke A: ");
  scanf("%f%f", &xa, &ya);

  printf("Unesite koordinate tacke B: ");
  scanf("%f%f", &xb, &yb);

  /* Provera da li su obe tacke u istom kvadrantu i ispis
     odgovarajuce poruke. */
  if ((xa >= 0 && ya >= 0 && xb >= 0 && yb >= 0) ||
      (xa <= 0 && ya >= 0 && xb <= 0 && yb >= 0) ||
      (xa >= 0 && ya <= 0 && xb >= 0 && yb <= 0) ||
      (xa <= 0 && ya <= 0 && xb <= 0 && yb <= 0)) {
    printf("Tacke se nalaze u istom kvadrantu.\n");
  } else {
    printf("Tacke se ne nalaze u istom kvadrantu.\n");
  }

  return 0;
}
