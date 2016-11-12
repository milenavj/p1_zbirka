/* Resenje pod c). */
#include <stdio.h>

int main()
{
  /* Promenljive koje oznacavaju granice intervala. */
  int n, m;
  /* Promenljiva koja oznacava trenutno ispisani broj intervala. */
  int i;

  printf("Unesi dva cela broja: ");
  scanf("%d%d", &n, &m);

  if (m < n) {
    printf
        ("Neispravan unos. Nisu dobro zadate granice intervala!\n");
    return -1;
  }

  /* Uslov petlje se proverava na kraju svake iteracije. */
  /* Zbog toga se do while petlja izvrsava bar jednom, cak i u
     slucaju da uslov petlje nikada nije ispunjen. */
  i = n;
  do {                          /* Petlja se zapocinje bez provere
                                   uslova. */
    printf("%d ", i);           /* Stampa se vrednost promenljive
                                   i. */
    i++;                        /* Uvecava se vrednost promenljive
                                   i. */
  }
  while (i <= m);               /* Proverava se uslov i ukoliko je
                                   ispunjen, nastavlja se sa
                                   sledecom iteracijom. */
  /* U suprotnom, petlja se zavrsava i program se nastavlja od prve 
     naredbe koja sledi za petljom. */
  printf("\n");

  return 0;
}
