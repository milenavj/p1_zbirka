#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, d, i;
  int x, y;
  int broj_parova = 0;

  /* Ucitavaju se vrednosti n i d i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite brojeve n i d: ");
  scanf("%d %d", &n, &d);

  if (n <= 1 || d < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  printf("Unesite n brojeva: ");

  /* Prvi broj se ucitava pre petlje. */
  scanf("%d", &x);

  for (i = 1; i < n; i++) {
    scanf("%d", &y);

    /* Provera se da li su brojevi na rastojanju d. */
    if (abs(y - x) == d)
      broj_parova++;

    /* Broj iz tekuce iteracije se cuva kako bi mogao da se
       upotrebljava u narednoj iteraciji. */
    x = y;
  }

  /* Ispis rezultata. */
  printf("Broj parova: %d\n", broj_parova);

  return 0;
}