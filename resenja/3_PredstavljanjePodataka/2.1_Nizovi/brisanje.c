#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n, i, j;
  char poslednja_cifra;
  int novo_n;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza:\n");
  scanf("%d", &n);
  if (n < 1 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza a. */
  printf("Unesite elemente niza a:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  /* Obilaze se svi elementi niza a. */
  for (i = 0, j = 0; i < n; i++) {

    /* Izdvaja se poslednja cifra tekuceg elementa. */
    poslednja_cifra = a[i] % 10;

    /* Ako je poslednja cifra nula ili je element deljiv svojom
       poslednjom cifrom, taj element se zadrzava i smesta na
       poziciju j. */
    if (poslednja_cifra == 0 || a[i] % poslednja_cifra == 0) {
      a[j] = a[i];
      j++;
    }
  }

  /* Dimenzija novog niza odgovara posledjoj vrednosti brojaca j. */
  novo_n = j;

  /* Ispisuje se rezultujuci niz. */
  printf("Niz a nakon izmena:\n");
  for (i = 0; i < novo_n; i++)
    printf("%d ", a[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
