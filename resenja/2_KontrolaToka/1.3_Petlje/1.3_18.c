#include <stdio.h>

int main()
{
  /* Deklaracije i inicijalizacije potrebnih promenljivih. */
  int x;
  int broj_brojeva = 0;
  int suma = 0;

  /* Brojevi se ucitavaju u petlji sve do unosa broja 0. */
  printf("Unesite brojeve: ");
  while (1) {
    scanf("%d", &x);

    if (x == 0)
      break;

    /* Procitani broj se dodaje na sumu. */
    suma += x;

    /* Uvecava se broj ucitanih brojeva. */
    broj_brojeva++;
  }

  /* Ispis rezultata.
     Napomena: primetiti da su i suma i broj_brojeva celi brojevi
     i da je neophodno bar jednu od te dve vrednosti pretvoriti
     u realan broj kako deljenje ne bi bilo celobrojno. */
  if (broj_brojeva == 0)
    printf("Nisu uneti brojevi.\n");
  else
    printf("Aritmeticka sredina: %.4f\n", 
           (double) suma / broj_brojeva);

  return 0;
}
