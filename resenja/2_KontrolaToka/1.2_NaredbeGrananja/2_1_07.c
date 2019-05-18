#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  unsigned int x;

  /* Ucitavanje vrednosti godine. */
  printf("Unesite godinu:");
  scanf("%u", &x);

  /* Provera da li je godina prestupna i ispis odgovarajuce poruke.
     Godina je prestupna ukoliko vazi jedan od narednih uslova:
     1. da je deljiva sa 4, a nije sa 100 
     2. da je deljiva sa 400. */
  if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
    printf("Godina je prestupna.\n");
  else
    printf("Godina nije prestupna.\n");

  return 0;
}
