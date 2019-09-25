#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b;

  /* Ucitavanje vrednosti a i b. */
  printf("Unesite vrednosti a i b: ");
  scanf("%d%d", &a, &b);

  /* Smestanje sume a + b u promenljivu a. */
  a = a + b;
  
  /* Smestanje izraza a - 2*b u promenljivu b. Uzimajuci u obzir
     promenu vrednosti promenljive a, u odnosu na pocetne vrednosti
     promenljivih a i b, vrednost ovog izraza je jednaka
     a + b - 2*b = a - b. */
  b = a - 2*b; 

  /* Ispis rezultata. */
  printf("Nove vrednosti su: a=%d, b=%d\n", a, b);

  return 0;
}
