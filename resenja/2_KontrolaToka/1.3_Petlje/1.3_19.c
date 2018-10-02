#include <stdio.h>

int main()
{
  float cena;
  int broj_artikla;
  float suma;

  broj_artikla = 0;
  suma = 0;

  printf("Unesite cene: ");

  while (1) {
    scanf("%f", &cena);

    if (cena == 0)
      break;

    if (cena < 0) {
      printf("Cena ne moze biti negativna.\n");
      return -1;
    }

    suma += cena;

    /* I uvecava se broj ucitanih brojeva. */
    broj_artikla++;
  }

  if (broj_artikla == 0)
    printf("Nisu unesene cene.\n");
  else
    printf("Aritmeticka sredina: %.4f\n", suma / broj_brojeva);

  return 0;
}
