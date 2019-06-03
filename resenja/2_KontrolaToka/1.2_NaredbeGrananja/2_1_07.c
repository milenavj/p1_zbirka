#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  unsigned int godina;

  /* Ucitavanje vrednosti godine. */
  printf("Unesite godinu:");
  scanf("%u", &godina);

  /* Provera da li je godina prestupna i ispis odgovarajuce poruke.
     Godina je prestupna ukoliko vazi jedan od narednih uslova:
     1. da je deljiva sa 4, a nije sa 100 
     2. da je deljiva sa 400. */
  if ((godina % 4 == 0 && godina % 100 != 0) || godina % 400 == 0)
    printf("Godina je prestupna.\n");
  else
    printf("Godina nije prestupna.\n");

  return 0;
}
