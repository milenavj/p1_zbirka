#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int brojevi[MAKS];
  int n, i, k, indikator;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &brojevi[i]);

  /* Ucitavanje broja k i provera ispravnosti ulaza. */
  printf("Unesite broj k: ");
  scanf("%d", &k);
  if (k == 0) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Promenljiva koja cuva informaciju o tome da li u nizu
     postoji element koji je deljiv brojem k. Inicijalna vrednost
     je 0. */
  indikator = 0;

  /* Ukoliko je element niza deljiv brojem k, indikator se
     postavlja na 1 i ispisuje se indeks tog elementa. */
  for (i = 0; i < n; i++) {
    if (brojevi[i] % k == 0) {
      indikator = 1;
      printf("%d ", i);
    }
  }

  /* Ukoliko je indikator jednak nuli to znaci da ne postoji
     element u nizu koji je deljiv brojem k. */
  if (indikator == 0)
    printf("U nizu nema elemenata koji su deljivi brojem %d.\n", k);

  exit(EXIT_SUCCESS);
}
