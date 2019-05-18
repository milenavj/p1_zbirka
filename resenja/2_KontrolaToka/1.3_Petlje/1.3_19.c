#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float cena, suma = 0;
  int broj_artikla = 0;

  /* Ucitavanje cena sve do unosa broja 0. */
  printf("Unesite cene: ");
  while (1) {
    scanf("%f", &cena);

    if (cena == 0)
      break;

    /* Provera ispravnosti ulaza. */
    if (cena < 0) {
      printf("Greska: neispravan unos cene.\n");
      return -1;
    }

    /* Uvecavanje sume za vrednost unete cene. */
    suma += cena;

    /* Uvecavanje broja unetih artikala za 1. */
    broj_artikla++;
  }

  /* Ispis rezultata. */
  if (broj_artikla == 0)
    printf("Nisu unete cene.\n");
  else
    printf("Prosecna cena: %.4f\n", suma / broj_artikla);

  return 0;
}
