#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int m, int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int m, n, i, j, suma_suseda;
  int k, t;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenziju matrice: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, m, n);

  /* Izracunavanje i ispis rezultata. */
  printf("Indeksi elemenata koji su jednaki zbiru suseda su:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++) {
      suma_suseda = 0;

      /* Racunanje sume elemenata podmatrice velicine 3*3
         ciji je centralni element a[i][j]. Pri racunanju ove sume
         vodi se racuna da se ne izadje iz okvira matice a. */
      for (k = i - 1; k <= i + 1; k++)
        for (t = j - 1; t <= j + 1; t++)
          if (k >= 0 && k < m && t >= 0 && t < n)
            suma_suseda += a[k][t];

      /* Od ukupne sume se oduzima tekuci element kako bi se dobio
         zbir elemenata koji su njegovi susedi. */
      suma_suseda -= a[i][j];

      /* Ukoliko je suma suseda jednaka tekucem elementu, ispisuju
         se indeksi tekuceg elementa matrice. */
      if (suma_suseda == a[i][j])
        printf("%d %d\n", i, j);
    }
  }
  return 0;
}
