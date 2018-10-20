/* Resenje pod a). */

#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, m, i;

  /* Ucitavaju se vrednosti granica intervala. */
  printf("Unesite granice intervala: ");
  scanf("%d%d", &n, &m);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (m < n) {
    printf("Greska: pogresan unos granica.\n");
    return -1;
  }

  /* Inicijalizacija brojaca na levu granicu intervala. */
  i = n;
  
  /* Ispisuju se sve vrednosti brojaca izmedju leve i desne
     granice intervala, ukljucujuci i same granice. */
  while (i <= m) {
    printf("%d ", i);
    i++;
  }

  printf("\n");

  return 0;
}
