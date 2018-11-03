#include <stdio.h>

int main()
{
  /* Deklaracija potrebne promenljive. */
  unsigned int x;

  /* Ucitava se vrednost godine. */
  printf("Unesite godinu:");
  scanf("%u", &x);

  /* Proverava se da li je godina prestupna ili ne i ispisuje se
     odgovarajuca poruka. Godina je prestupna ukoliko vazi jedan od
     narednih uslova:
     1. da je deljiva sa 4, a nije sa 100 
     2. da je deljiva sa 400. */
  if ((x % 4 == 0 && x % 100 != 0) || x % 400 == 0)
    printf("Godina je prestupna.\n");
  else
    printf("Godina nije prestupna.\n");

  return 0;
}
