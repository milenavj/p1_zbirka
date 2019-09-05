#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int cena1, cena2, cena3, najjeftiniji;
  int cena_bez_popusta, cena_sa_popustom;

  /* Ucitavanje vrednosti cena. */
  printf("Unesite tri cene: ");
  scanf("%d%d%d", &cena1, &cena2, &cena3);

  /* Provera ispravnosti ulaznih podataka. */
  if (cena1 <= 0 || cena2 <= 0 || cena3 <= 0) {
    printf("Greska: neispravan unos cene.");
    return 1;
  }

  /* Racunanje vrednosti najjeftinijeg artikla. */
  najjeftiniji = cena1;

  if (cena2 < najjeftiniji)
    najjeftiniji = cena2;

  if (cena3 < najjeftiniji)
    najjeftiniji = cena3;

  /* Racunanje cene sa i bez popusta. */
  cena_bez_popusta = cena1 + cena2 + cena3;
  cena_sa_popustom = cena_bez_popusta - najjeftiniji + 1;

  /* Ispis rezultata. */
  printf("Cena sa popustom: %d din\n", cena_sa_popustom);
  printf("Usteda: %d din\n", cena_bez_popusta - cena_sa_popustom);

  return 0;
}
