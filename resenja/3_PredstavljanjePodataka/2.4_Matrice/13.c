#include <stdio.h>
#include <stdlib.h>

#define MAKS 200

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

/* Funkcija racuna skalarni proizvod i-te i j-te vrste matrice. */
int skalarni_proizvod(int a[][MAKS], int n, int i, int j) {
  int suma = 0, k;

  for (k = 0; k < n; k++)
    suma += a[i][k] * a[j][k];

  return suma;
}

/* Matrica je ortonormirana ukoliko je skalarni proizvod svakog
   para razlicitih vrsta jednak nuli, a skalarni proizvod svake
   vrste same sa sobom jednak jedinici. Funkcija proverava da li je 
   matrica ortorormirana i vraca jedinicu ukoliko jeste, a nulu
   inace. */
int ortonormirana(int a[][MAKS], int n) {
  int i, j;

  /* Za svaki par vrsta se racuna skalarni proizvod i proverava da
     li je uslov ispunjen. Ukoliko nije, kao povratna vrednost
     funkcije se vraca nula. */
  for (i = 0; i < n; i++)
    for (j = i; j < n; j++) {
      /* Provera za slucaj kada se racuna skalarni proizvod vrste
         same sa sobom. */
      if (i == j && skalarni_proizvod(a, n, i, i) != 1)
        return 0;

      /* Provera za par razlicitih vrsta. */
      if (i != j && skalarni_proizvod(a, n, i, j) != 0)
        return 0;
    }

  /* Ako je izvrsavanje stiglo do kraja petlje, znaci da je uslov
     ispunjen za sve vrste, tj. da je matrica ortonormirana. */
  return 1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int n;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta matrice: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, n);

  /* Ispis rezultata. */
  if (ortonormirana(a, n))
    printf("Matrica jeste ortonormirana.\n");
  else
    printf("Matrica nije ortonormirana.\n");

  return 0;
}
