/* Resenje pod c). */
#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, m, i;

  /* Ucitavanje granice intervala. */
  printf("Unesite granice intervala: ");
  scanf("%d%d", &n, &m);

  /* Provera ispravnosti ulaznih podataka. */
  if (m < n) {
    printf("Greska: pogresan unos granica.\n");
    return -1;
  }

  /* Inicijalizacija brojaca na levu granicu intervala. */
  i = n;

  /* Uslov petlje se proverava na kraju svake iteracije. Zbog toga
     se do while petlja izvrsava bar jednom, cak i u slucaju da
     uslov petlje nikada nije ispunjen. */
  do {
    printf("%d ", i);
    i++;
  }
  while (i <= m);

  printf("\n");

  return 0;
}
