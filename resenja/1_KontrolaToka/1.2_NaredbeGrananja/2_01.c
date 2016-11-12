#include <stdio.h>

int main()
{
  int a, b, min;
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &a, &b);

  /* Promenljiva min dobija vrednost promenljive a. */
  min = a;

  /* Ako je b<a, promenljiva min ce promeniti vrednost tj. bice joj 
     dodeljena vrednost promenljive b. U suprotnom, vrednost ostaje 
     ista. */

  if (b < a)
    min = b;

  printf("Minimum je %d\n", min);

  return 0;
}
