#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Brojac i odredjuje koliko redova se ispisuje. Radi lakseg
     izracunavanja koliko zvezdica i praznina je potrebno ispisati
     u svakom redu, i se postavlja na n-1 i smanjuje u svakoj
     iteraciji petlje. */
  for (i = n - 1;; i--) {
    /* Prvo se ispisuju beline koje prethode karakterima *. */
    for (j = 0; j < n - i + 1; j++)
      printf(" ");
    /* Posle belina se ispisuje potreban broj karaktera *. */
    for (j = 0; j < 2 * i + 1; j++)
      printf("*");
    printf("\n");

    /* Posebna paznja mora da se obrati na cinjenicu da su brojaci
       tipa unsigned int. Problem nastaje kada je i==0 i pokusa se
       oduzimanje (i--). Posto su brojevi unsigned, nova vrednost
       nece biti -1, vec pozitivan ceo broj. Imajuci to na umu,
       uslov i>=0 ne moze da se stavi u uslov za for petlju. Mnogo
       sigurnije je brojace deklarisati da budu tipa int i izbeci
       ovakvu vrstu problema. */
    if (i == 0)
      break;
  }

  return 0;
}
