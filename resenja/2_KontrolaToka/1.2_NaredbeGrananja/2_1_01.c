#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c, najmanji;

  /* Ucitavaju se ulazne vrednosti. */
  printf("Unesite tri cela broja: ");
  scanf("%d%d%d", &a, &b, &c);

  /* Najmanji broj se inicijalizuje na vrednost prvog broja. */
  najmanji = a;

  /* Ako je vrednost drugog broja manji od vrednosti tekuceg
     minimuma, vrednost minimuma se azurira. */
  if (b < najmanji)
    najmanji = b;

  /* Postupak se ponavlja za treci broj. */
  if (c < najmanji)
    najmanji = c;

  /* Ispis rezultata. */
  printf("Najmanji: %d\n", najmanji);

  return 0;
}
