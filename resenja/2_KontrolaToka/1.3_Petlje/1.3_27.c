#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int x, cifra;
  unsigned int rezultat;
  int pozicija;

  /* Ucitava se vrednost broja x i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj: ");
  scanf("%d", &x);

  if (x <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Inicijalizacija pozicije i rezultata.
     Pozicija oznacava tezinu trenutne cifre i moze imati vrednosti
     1, 10, 100, 1000, ... */
  pozicija = 1;
  rezultat = 0;

  /* U petlji se izdvaja cifra po cifra, dok god ima neobradjenih
     cifara. */
  while (x > 0) {

    /* Izdvaja se poslednja cifra iz zapisa i ako je njena vrednost
       paran broj, uvecava se za 1. */
    cifra = x % 10;
    if (cifra % 2 == 0)
      cifra++;

    /* Novi broj se formira tako sto se izdvojena cifra pomnozi
       odgovarajucom tezinom (stepenom) pozicije i doda na tekuci
       rezultat. */
    rezultat += cifra * pozicija;

    /* Uklanja se poslednja cifra broja. */
    x /= 10;

    /* Pozicija se mnozi sa 10. */
    pozicija *= 10;
  }

  /* Ispisuje se izracunatu vrednost. */
  printf("Rezultat: %d\n", rezultat);

  return 0;
}
