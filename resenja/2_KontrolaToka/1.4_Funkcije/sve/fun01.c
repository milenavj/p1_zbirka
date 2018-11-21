#include <stdio.h>

/* Funkcija racuna minimum tri cela broja.
   Promenljive u listi argumenata funkcije (x, y i z), kao i one
   deklarisane u samoj funkciji (minimum), lokalne su za tu
   funkciju, sto znaci da im se ne moze pristupiti nigde izvan
   funkcije min. */
int min(int x, int y, int z)
{
  /* Vrednost minimuma se postavlja na vrednost broja x. */
  int minimum = x;

  /* Vrsi se poredjenje sa druga dva broja i po potrebi
     azuriranje vrednosti minimuma. */
  if (minimum > y)
    minimum = y;
  if (minimum > z)
    minimum = z;

  /* Vrednost minimuma se vraca kao povratna vrednost funkcije. */
  return minimum;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int x, y, z;

  /* Ucitavaju se vrednosti tri broja. */
  printf("Unesite brojeve: ");
  scanf("%d%d%d", &x, &y, &z);

  /* Poziv funkcije i ispis rezultata. */
  printf("Minimum: %d\n", min(x, y, z));

  return 0;
}
