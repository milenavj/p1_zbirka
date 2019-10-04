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

/* Funkcija proverava da li je matrica b podmatrica matrice a i
   vraca jedinicu ukoliko jeste, a nulu inace. */
int podmatrica(int a[][MAKS], int m, int n,
               int b[][MAKS], int k, int t) {
  int i, j, x, y;
  int jeste_podmatrica;

  for (i = 0; i <= m - k; i++) {
    for (j = 0; j <= n - t; j++) {
      /* Za svaku poziciju (i,j) se proverava da li je podmatrica
         dimenzije k*t ciji je gornji levi ugao a[i][j] jednaka
         matrici b. */
      jeste_podmatrica = 1;
      for (x = 0; x < k && jeste_podmatrica; x++)
        for (y = 0; y < t && jeste_podmatrica; y++)
          if (a[i + x][j + y] != b[x][y])
            jeste_podmatrica = 0;

      if (jeste_podmatrica)
        return 1;
    }
  }
  
  return 0;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS], b[MAKS][MAKS];
  int m, n, k, t;

  /* Ucitavanje dimenzije matrice A i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta i broj kolona matrice A: ");
  scanf("%d%d", &m, &n);
  if (n <= 0 || n > MAKS || m <= 0 || m > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata prve matrice. */
  ucitaj(a, m, n);

  /* Ucitavanje dimenzije matrice B i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta i broj kolona matrice B: ");
  scanf("%d%d", &k, &t);
  if (k <= 0 || k > MAKS || t <= 0 || t > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata druge matrice. */
  ucitaj(b, k, t);

  /* Ispis rezultata. */
  if (podmatrica(a, m, n, b, k, t))
    printf("Druga matrica je sadrzana u prvoj matrici.\n");
  else
    printf("Druga matrica nije sadrzana u prvoj matrici.\n");

  exit(EXIT_SUCCESS);
}
