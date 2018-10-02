#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  float a, b;
  float obim, povrsina;

  /* Ucitavaju se duzine stranica pravougaonika. */
  printf("Unesite duzine stranica pravougaonika: ");
  scanf("%f%f", &a, &b);

  /* Izracunava se obim pravougaonika. */
  obim = 2 * (a + b);

  /* Izracunava se povrsina pravougaonika. */
  povrsina = a * b;

  /* Ispis rezultata na dve decimale. */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);

  return 0;
}
