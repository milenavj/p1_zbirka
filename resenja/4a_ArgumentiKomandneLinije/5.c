#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  /* Deklaracija potrebnih promenljivih. */
  int i, brojac = 0;

  /* Prebrojavanje argumenata koji sadrze karakter @. */
  for (i = 1; i < argc; i++)
    if (strchr(argv[i], '@') != NULL)
      brojac++;

  /* Ispis rezultata. */
  printf("Rezultat: %d\n", brojac);

  return 0;
}
