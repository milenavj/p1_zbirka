#include <stdio.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  float cena, suma = 0;
  int broj_artikla = 0;

  /* Cene se ucitavaju sve do unosa broja 0. */
  printf("Unesite cene: ");
  while (1) {
    scanf("%f", &cena);

    if (cena == 0)
      break;

    /* Vrsi se provera korektnosti ulaza. */
    if (cena < 0) {
      printf("Greska: neispravan unos cene.\n");
      return -1;
    }

    /* Suma se uvecava za vrednost unete cene. */
    suma += cena;

    /* Broj unetih artikala se uvecava za 1. */
    broj_artikla++;
  }

  /* Ispis rezultata. */
  if (broj_artikla == 0)
    printf("Nisu unesene cene.\n");
  else
    printf("Prosecna cena: %.4f\n", suma / broj_artikla);

  return 0;
}