#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int b[MAKS];
  int n, i, skalarni_proizvod;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju vektora: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje koordinata vektora. */
  printf("Unesite koordinate vektora a: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  printf("Unesite koordinate vektora b: ");
  for (i = 0; i < n; i++)
    scanf("%d", &b[i]);

  /* Racunanje skalarnog proizvoda po zadatoj formuli. */
  skalarni_proizvod = 0;
  for (i = 0; i < n; i++)
    skalarni_proizvod += a[i] * b[i];

  /* Ispis rezultata. */
  printf("Skalarni proizvod: %d\n", skalarni_proizvod);

  exit(EXIT_SUCCESS);
}
