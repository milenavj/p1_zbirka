#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  float a, b, obim, povrsina;

  /* Ucitavanje duzina stranica pravougaonika. */
  printf("Unesite duzine stranica pravougaonika: ");
  scanf("%f%f", &a, &b);

  /* Racunanje obima pravougaonika. */
  obim = 2 * (a + b);

  /* Racunanje povrsine pravougaonika. */
  povrsina = a * b;

  /* Ispis rezultata na dve decimale. */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);

  return 0;
}
