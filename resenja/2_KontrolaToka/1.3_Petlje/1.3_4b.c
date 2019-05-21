/* Resenje pod b). */

#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, m, i;

  /* Ucitavanje vrednosti granica intervala. */
  printf("Unesite granice intervala: ");
  scanf("%d%d", &n, &m);

  /* Provera ispravnosti ulaznih podataka. */
  if (m < n) {
    printf("Greska: pogresan unos granica.\n");
    return 1;
  }

  /* Naredba i=n se izvrsava jednom, pre prve iteracije. Uslov
     petlje i<=m se proverava pre svake iteracije. Naredba i++ se
     izvrsava nakon svake iteracije. */
  for (i = n; i <= m; i++)
    printf("%d ", i);

  printf("\n");

  return 0;
}
