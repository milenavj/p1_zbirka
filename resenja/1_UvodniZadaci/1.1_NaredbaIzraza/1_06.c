#include <stdio.h>

int main()
{
  /* Deklaracija promenljivih cija je vrednost neoznacen ceo broj. */
  unsigned int cena, kolicina, iznos;
  unsigned int kusur;

  /* Ucitavaju se vrednosti cene, kolicine i iznosa. */
  printf("Unesite cenu, kolicinu i iznos: ");
  scanf("%u%u%u", &cena, &kolicina, &iznos);

  /* Izracunava se kusur. */
  kusur = iznos - kolicina * cena;

  /* Ispis vrednosti kusura. */
  printf("Kusur je %u dinara.\n", kusur);

  return 0;
}
