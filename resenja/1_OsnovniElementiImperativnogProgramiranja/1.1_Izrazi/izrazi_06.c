#include <stdio.h>

int main() {
  /* Deklaracija promenljivih cija je vrednost neoznacen ceo broj. */
  unsigned int cena, kolicina, iznos, kusur;

  /* Ucitavanje vrednosti cene, kolicine i iznosa. */
  printf("Unesite cenu, kolicinu i iznos:\n");
  scanf("%u%u%u", &cena, &kolicina, &iznos);

  /* Racunanje kusura. */
  kusur = iznos - kolicina * cena;

  /* Ispis vrednosti kusura. */
  printf("Kusur: %u dinara\n", kusur);

  return 0;
}
