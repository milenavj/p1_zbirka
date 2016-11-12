#include <stdio.h>

int main()
{
  int x;
  /* Tezina trenutne pozicije u broju. Moze biti 1, 10, 100, 1000
     itd. */
  int pozicija;
  /* Trenutna izdvojena cifra iz broja x. */
  int cifra;
  /* Broj dobijen nakon transformacije. */
  unsigned int y;

  printf("Unesite broj: ");
  scanf("%d", &x);


  if (x <= 0) {
    printf("Nekorektan unos.\n");
    return -1;
  }

  /* Posto pocinjemo sa izdvajanjem cifara od cifre jedinica,
     postavlja se tezinu (stepen) pozicije na 1. */
  pozicija = 1;
  y = 0;

  /* Provera da li ima cifara u zapisu broja. */
  while (x > 0) {

    /* Izdvaja se poslednja cifra iz zapisa. */
    cifra = x % 10;

    /* Provera da li je cifra parna. */
    if (cifra % 2 == 0) {
      /* I ako jeste, uvecava se. */
      cifra++;

    }

    /* Novi broj se formira tako sto se izdvojena cifra pomnozi
       odgovarajucom tezinom (stepenom) pozicije. */
    y += cifra * pozicija;

    /* Priprema se broj za izdvajanje naredne cifre, uklanja se
       poslednja cifra broja. */
    x /= 10;

    /* Uvecava se tezinu (stepen) pozicije. */
    pozicija *= 10;
  }

  /* Ispisuje se izracunatu vrednost. */
  printf("%d\n", y);

  return 0;
}
