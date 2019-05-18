#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a, b, c, najjeftiniji;
  int cena_bez_popusta, cena_sa_popustom;

  /* Ucitavanje vrednosti cena. */
  printf("Unesite tri cene: ");
  scanf("%d%d%d", &a, &b, &c);

  /* Provera ispravnosti ulaznih podataka. */
  if (a <= 0 || b <= 0 || c <= 0) {
    printf("Greska: neispravan unos cene.");
    return -1;
  }

  /* Racunanje vrednosti najjeftinijeg artikla. */
  najjeftiniji = a;

  if (b < najjeftiniji)
    najjeftiniji = b;

  if (c < najjeftiniji)
    najjeftiniji = c;

  /* Racunanje cene sa i bez popusta. */
  cena_bez_popusta = a + b + c;
  cena_sa_popustom = cena_bez_popusta - najjeftiniji + 1;

  /* Ispis rezultata. */
  printf("Cena sa popustom: %d din\n", cena_sa_popustom);
  printf("Usteda: %d din\n", cena_bez_popusta - cena_sa_popustom);

  return 0;
}
