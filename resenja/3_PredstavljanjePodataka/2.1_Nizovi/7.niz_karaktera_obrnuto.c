#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char karakteri[MAKS];
  char c;
  int i, n;

  /* Ucitavanje karaktera sve do unosa zvezdice ili do prekoracenja
     maksimalnog broja karaktera. */
  for (i = 0; i < MAKS; i++) {
    printf("Unesite karakter: ");
    scanf("%c", &c);
    /* Citanje znaka za novi red nakon unetog karaktera. */
    getchar();

    /* Ukoliko je unet karakter * izlazi se iz petlje. */
    if (c == '*')
      break;

    /* Smestanje procitanog karaktera u niz. */
    karakteri[i] = c;
  }

  /* Broj unetih karaktera nakon izlaska iz petlje je i. */
  n = i;

  /* Ispis karaktera u obrnutom redosledu. */
  for (i = n - 1; i >= 0; i--)
    printf("%c ", karakteri[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
