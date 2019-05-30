#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

/* Funkcija proverava da li je kolona j sortirana rastuce i vraca
   jedinicu ukoliko jeste, a nulu inace. */
int sortirana_kolona(int a[][MAKS], int n, int j) {
  int i;

  for (i = 0; i < n - 1; i++)
    if (a[i][j] >= a[i + 1][j])
      return 0;

  return 1;
}

/* Funkcija proverava da li je svaka kolona matrice sortirana
   rastuce i vraca jedinicu ukoliko jeste, a nulu inace. */
int sortirani_po_kolonama(int a[][MAKS], int n) {
  int j;

  for (j = 0; j < n; j++)
    if (!sortirana_kolona(a, n, j))
      return 0;

  return 1;
}

/* Funkcija proverava da li je i-ta vrsta sortirana rastuce i vraca
   jedinicu ukoliko jeste, a nulu inace. */
int sortirana_vrsta(int a[][MAKS], int n, int i) {
  int j;

  for (j = 0; j < n - 1; j++)
    if (a[i][j] >= a[i][j + 1])
      return 0;

  return 1;
}

/* Funkcija proverava da li je svaka vrsta matrice sortirana
   rastuce i vraca jedinicu ukoliko jeste, a nulu inace. */
int sortirani_po_vrstama(int a[][MAKS], int n) {
  int i;

  for (i = 0; i < n; i++)
    if (!sortirana_vrsta(a, n, i))
      return 0;

  return 1;
}

/* Funkcija proverava da li je glavna dijagonala matrice sortirana
   rastuce i vraca jedinicu ukoliko jeste, a nulu inace. */
int sortirana_glavna(int a[][MAKS], int n) {
  int i;

  for (i = 0; i < n - 1; i++)
    if (a[i][i] >= a[i + 1][i + 1])
      return 0;

  return 1;
}

/* Funkcija proverava da li je sporedna dijagonala matrice
   sortirana rastuce i vraca jedinicu ukoliko jeste, a nulu inace. */
int sortirana_sporedna(int a[][MAKS], int n) {
  int i;

  for (i = 0; i < n - 1; i++)
    if (a[i][n - i - 1] >= a[i + 1][n - i - 2])
      return 0;

  return 1;
}

/* Funkcija proverava da li su obe dijagonale matrice sortirane
   rastuce i vraca jedinicu ukoliko jesu, a nulu inace. */
int sortirani_po_dijagonalama(int a[][MAKS], int n) {
  return sortirana_glavna(a, n) && sortirana_sporedna(a, n);
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
  if (sortirani_po_kolonama(a, n))
    printf("Elementi su sortirani po kolonama.\n");
  else
    printf("Elementi nisu sortirani po kolonama.\n");

  if (sortirani_po_vrstama(a, n))
    printf("Elementi su sortirani po vrstama.\n");
  else
    printf("Elementi nisu sortirani po vrstama.\n");

  if (sortirani_po_dijagonalama(a, n))
    printf("Elementi su sortirani po dijagonalama.\n");
  else
    printf("Elementi nisu sortirani po dijagonalama.\n");

  return 0;
}
