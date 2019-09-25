#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  float a11, a12, a21, a22, determinanta;

  /* Ucitavanje elemenata matrice. */
  printf("Unesite brojeve: ");
  scanf("%f%f%f%f", &a11, &a12, &a21, &a22);

  /* Racunanje determinante matrice. */
  determinanta = a11*a22 - a12*a21;
  
  /* Ispis rezultata na cetiri decimale. */
  printf("Determinanta: %.4f\n", determinanta);

  return 0;
}
