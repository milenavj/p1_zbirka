#include <stdio.h>

int main()
{
  /* Deklaracija i ucitavanje cene proizvoda. */
  unsigned int x;
  printf("Unesite cenu proizvoda:");
  scanf("%u", &x);

  /* Vrednost x/5000 predstavlja maksimalan broj novcanica od 5000 dinara koje je moguce iskoristiti za placanje racuna.
    Na primer, neka je uneta cena 8367 dinara, vrednost izraza 8367/5000 je jednaka 1. */
  printf("%u = %u*5000 + ", x, x / 5000);
  
  /* Da bi se isti postupak primenio i na ostale novcanice, potrebno je izracunati preostali iznos. Jedan nacin da se to uradi je racunanje ostatka pri deljenju unete vrednosti x (u primeru 8367) sa 5000. On iznosi 3367. Ovu vrednost dodeljujemo promeljivoj x. */
  x = x % 5000;

  /* Postupak se ponavlja i za za ostale novcanice. */
  printf("%u*2000 + ", x / 2000);
  x = x % 2000;
  printf("%u*1000 + ", x / 1000);
  x = x % 1000;
  printf("%u*500 + ", x / 500);
  x = x % 500;
  printf("%u*200 + ", x / 200);
  x = x % 200;
  printf("%u*100 + ", x / 100);
  x = x % 100;
  printf("%u*50 + ", x / 50);
  x = x % 50;
  printf("%u*20 + ", x / 20);
  x = x % 20;
  printf("%u*10 + ", x / 10);
  x = x % 10;
  printf("%u*1\n", x);

  return 0;
}
