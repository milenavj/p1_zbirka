#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS];
  int n, i;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza:\n");
  scanf("%d", &n);
  if (n < 1 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesi elemente niza:\n");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  /* Ispisuju se elementi niza na parnim pozicijama. */
  printf("Elementi niza na parnim pozicijama:\n");
  for (i = 0; i < n; i += 2)
    printf("%d ", a[i]);
  printf("\n");

  /* Ispisuju se parni elementi niza. */
  printf("Parni elementi niza:\n");
  for (i = 0; i < n; i++)
    if (a[i] % 2 == 0)
      printf("%d ", a[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
