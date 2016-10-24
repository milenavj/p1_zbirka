#include <stdio.h>

int main()
{
  /* Pamtimo uzastopna dva Fibonacijeva broja i na osnovu njih racunamo sledeci. */
  /* Promenljive prvi i drugi su brojevi koje pamtimo i na osnovu njih racunamo treci. */
  /* Na osnovu teksta zadatka, promenljive prvi i drugi postavljamo na 1. */
	int prvi = 1;
  int drugi = 1;
  int treci;
  /* Promenljiva pozicija je podatak koji ucitavamo i odnosi se na poziciju u Fibonacijevom nizu
     za koju treba izracunati vrednost. */
  int pozicija;
  /* Promenljiva i oznacava do koje pozicije smo izracunali vrednosti. Kako imamo prve dve
     vrednosti, ovu promenljivo postavljamo na 2. */
  int i = 2;

	printf("Unesite poziciju u Fibonacijevom nizu: ");
	scanf("%d", &pozicija);

  /* Pozicija ne moze biti 0 i ne moze biti negativan broj. */
	if (pozicija < 1)
  {
		printf("Neispravan unos. Pozicija u Fibonacijevom nizu mora biti pozitivan broj koji nije 0!\n");
	  return -1;
  }

	while(i < pozicija)
  {
    /* Na osnovu dva uzastopna racunamo treci. */
		treci = prvi + drugi;

    /* Potom razmenjujemo vrednosti. Uzastopna dva koja pamtimo postaju
       sledeca uzastopna dva broja Fibonacijevog niza. */
		prvi = drugi;
		drugi = treci;

    /* Prelazimo na racunanje sledeceg broja na sledecoj poziciji. */
		i++;
	}

	printf("Trazeni broj je: %d\n", drugi);

	return 0;
}
