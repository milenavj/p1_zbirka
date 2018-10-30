#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS], c[2 * MAKS];
  int i, n;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n < 1 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi nizova */
  printf("Unesite elemente niza a: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);

  printf("Unesite elemente niza b: ");
  for (i = 0; i < n; i++)
    scanf("%d", &b[i]);

  /* Niz c ima 2*n elemenata: prvih n elemenata su elementi niza b, 
     a narednih n elemenata elementi niza a. Elementi niza b se
     nalaze na pozicijama 0,1,2,...n-1, a elementi niza a na
     pozicijama n,n+1,...2*n-1. Jednim prolaskom kroz petlju na
     poziciju i u nizu c se postavlja element b[i] niza b, a na
     poziciju n+i element a[i] niza a. */
  for (i = 0; i < n; i++) {
    c[i] = b[i];
    c[n + i] = a[i];
  }

  /* Ispisuju se elementi niza c. */
  for (i = 0; i < 2 * n; i++)
    printf("%d ", c[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
