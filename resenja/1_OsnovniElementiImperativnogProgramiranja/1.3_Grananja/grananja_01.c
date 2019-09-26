#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c, najmanji;

  /* Ucitavanje ulaznih vrednosti. */
  printf("Unesite tri cela broja: ");
  scanf("%d%d%d", &a, &b, &c);

  /* Inicijalizovanje najmanjeg broja na vrednost prvog broja. */
  najmanji = a;

  /* Azuriranje vrednosti minimuma u slucaju da je vrednost drugog
     broja manja od vrednosti tekuceg minimuma. */
  if (b < najmanji)
    najmanji = b;

  /* Ponavljanje postupka za treci broj. */
  if (c < najmanji)
    najmanji = c;

  /* Ispis rezultata. */
  printf("Najmanji: %d\n", najmanji);

  return 0;
}
