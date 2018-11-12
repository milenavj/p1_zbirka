#include<stdio.h>
#include<stdlib.h>

#define BROJ_CIFARA 10

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int x, x_original, cifra, i;
  int brojaci[BROJ_CIFARA];

  /* Ucitava se ceo broj sa standardnog ulaza. */
  printf("Unesite ceo broj:\n");
  scanf("%d", &x);

  /* Cuva se njegova x_originalna vrednost zbog finalnog ispisa. */
  x_original = x;
  x = abs(x);

  /* Svaki element niza brojaci predstavlja brojac za jednu od
     cifara: brojac[0] predstavlja broj nula u zapisu broja x
     brojac[1] predstavlja broj jedinica u zapisu broja x ...
     brojac[9] predstavlja broj devetki u zapisu broja x. */

  /* Brojaci se na pocetku inicijalizuju nulama. */
  for (i = 0; i < BROJ_CIFARA; i++)
    brojaci[i] = 0;

  /* Sve dok ima cifara u zapisu broja x */
  do {
    /* Izdvaja se krajnja desna cifara. */
    cifra = x % 10;

    /* Uvecava se njen broj pojavljivanja. */
    brojaci[cifra]++;

    /* Prelazi se na analiziranje sledece cifre. */
    x /= 10;
  } while (x);

  /* Ispisuju se informacije o ciframa koje se nalaze u zapisu
     broja x. */
  for (i = 0; i < BROJ_CIFARA; i++) 
  {
    if (brojaci[i]) 
    {
      printf("U zapisu broja %d, cifra %d se pojaviljuje %d puta\n",
             x_original, i, brojaci[i]);
    }
  }

  exit(EXIT_SUCCESS);
}
