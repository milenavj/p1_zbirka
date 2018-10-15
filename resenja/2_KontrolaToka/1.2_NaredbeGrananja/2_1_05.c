#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c;
  int najjeftiniji;
  int cena_bez_popusta, cena_sa_popustom;

  /* Ucitavaju se vrednosti cena. */
  printf("Unesite tri cene: ");
  scanf("%d%d%d", &a, &b, &c);

  /* Vrsi se provera ispravnosti ulaznih podataka. */
  if (a <= 0 || b <= 0 || c <= 0) {
    printf("Greska: neispravan unos cene.");
    return -1;
  }

  /* Racuna se vrednost najjeftinijeg artikla. */
  najjeftiniji = a;

  if (b < najjeftiniji)
    najjeftiniji = b;

  if (c < najjeftiniji)
    najjeftiniji = c;

  /* Racunaju se cene sa i bez popusta. */
  cena_bez_popusta = a + b + c;
  cena_sa_popustom = cena_bez_popusta - najjeftiniji + 1;

  /* Ispis rezultata. */
  printf("Cena sa popustom: %d din\n", cena_sa_popustom);
  printf("Usteda: %d din\n", cena_bez_popusta - cena_sa_popustom);

  return 0;
}
