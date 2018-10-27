#include <stdio.h>

int euklid(int x, int y)
{
  int ostatak;
  /* Euklidov algoritam: trazi se nzd(x,y). 
     Na primer nzd(12,18). Postupak koji se primenjuje je sledeci:
     1. ostatak = x % y = 12 % 18 = 12.
     2. x postaje y => x = 18
     3. y postaje ostatak => y = 12
     =>
     1. ostatak = x % y = 18 % 12 = 6
     2. x postaje y => x = 12
     3.y postaje ostatak => y = 6
     =>
     1. ostatak = x % y = 12 % 6 = 0
     2. x postaje y => x = 6
     3. y postaje ostatak => y = 0
     => procedura se zavrsava jer je y jednako 0, a 
     rezultat je poslednji ne-nula ostatak, tj. x.*/
  while (y) {
    ostatak = x % y;
    x = y;
    y = ostatak;
  }

  /* Kao povratna vrednost funkcije se vraca x. */
  return x;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b;

  /* Ucitavaju se vrednosti a i b. */
  printf("Unesite dva cela broja:");
  scanf("%d%d", &a, &b);

  /* Ispis rezultata. */
  printf("Najveci zajednicki delilac: %d\n", euklid(a, b));

  return 0;
}
