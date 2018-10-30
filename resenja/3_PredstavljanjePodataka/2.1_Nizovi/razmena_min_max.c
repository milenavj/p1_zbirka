#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int brojevi[MAKS];
  int n, i;
  int pozicija_najveceg, pozicija_najmanjeg, najveci, najmanji;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n < 1 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:\n");
  for (i = 0; i < n; i++)
    scanf("%d", &brojevi[i]);

  /* Najvecim, kao i najmanjim elementom niza proglasava se nulti
     element niza. Pozicije najveceg i najmanjeg elementa se
     postavljaju na 0. */
  najveci = brojevi[0];
  najmanji = brojevi[0];
  pozicija_najveceg = 0;
  pozicija_najmanjeg = 0;

  /* U prolazu kroz niz trazi se najveci i najmanji element i
     pamte se njihove pozicije. */
  for (i = 1; i < n; i++) {
    if (brojevi[i] > najveci) {
      najveci = brojevi[i];
      pozicija_najveceg = i;
    }

    if (brojevi[i] < najmanji) {
      najmanji = brojevi[i];
      pozicija_najmanjeg = i;
    }
  }

  /* Zamenjuju se elementi na pozicijama pozicija_najmanjeg i pozicija_najveceg. */
  brojevi[pozicija_najveceg] = najmanji;
  brojevi[pozicija_najmanjeg] = najveci;

  /* Ispisuje se rezultujuci niz. */
  for (i = 0; i < n; i++)
    printf("%d ", brojevi[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
