#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x, y;
  int p;

  /* Ucitavaju se vrednosti x i y. */
  printf("Unesite dve celobrojne vrednosti:");
  scanf("%d%d", &x, &y);

  /* Ispis vrednosti promenljivih pre zamene. */
  printf("Pre zamene: x=%d, y=%d\n", x, y);

  /* Pomocna promenljiva p je potrebna da sacuva vrednost
     promenljive x pre nego sto se ona izmeni i dobije vrednost
     promenljive y. */
  p = x;
  x = y;
  y = p;
  
  /* Ispis vrednosti promenljivih nakon zamene. */
  printf("Posle zamene: x=%d, y=%d\n", x, y);

  return 0;
}
