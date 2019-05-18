#include <stdio.h>

int main() {
  /* Deklaracija celobrojne promenljive. */
  int n;

  /* Ucitavanje vrednosti celog broja. */
  printf("Unesite ceo broj: ");
  scanf("%d", &n);
  
  /* Ispis kvadratne vrednosti unetog broja. */
  printf("Kvadrat: %d\n", n * n);
  
  /* Ispis kubne vrednosti unetog broja. */
  printf("Kub: %d\n", n * n * n);

  return 0;
}
