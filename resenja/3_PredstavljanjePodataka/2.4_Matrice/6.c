#include <stdio.h>
#include <stdlib.h>

#define MAKS 50

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(float a[][MAKS], int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%f", &a[i][j]);
}

/* Funkcija racuna trag matrice. */
float trag(float a[][MAKS], int n) {
  float suma = 0;
  int i;

  for (i = 0; i < n; i++)
    suma += a[i][i];

  return suma;
}

/* Funkcija racuna sumu elemenata koji se nalaze na sporednoj
   dijagonali matrice. */
float suma_sporedna(float a[][MAKS], int n) {
  float suma = 0;
  int i;

  for (i = 0; i < n; i++)
    suma += a[i][n - i - 1];

  return suma;
}

/* Funckija racuna sumu elemenata koji se nalaze iznad glavne
   dijagonale matrice. */
float suma_iznad(float a[][MAKS], int n) {
  float suma = 0;
  int i, j;

  for (i = 0; i < n; i++)
    for (j = i + 1; j < n; j++)
      suma += a[i][j];

  return suma;
}

/* Funkcija racuna sumu elemenata koji se nalaze ispod sporedne
   dijagonale matrice. */
float suma_ispod(float a[][MAKS], int n) {
  float suma = 0;
  int i, j;

  for (i = 0; i < n; i++)
    for (j = n - i - 1; j > i; j--)
      suma += a[i][j];

  return suma;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  float a[MAKS][MAKS];
  int n;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite dimenziju matrice: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, n);

  /* Ispis rezultata. */
  printf("Trag je %.2f.\n", trag(a, n));
  printf("Suma na sporednoj dijagonali je %.2f.\n",
         suma_sporedna(a, n));
  printf("Suma iznad glavne dijagonale je %.2f.\n",
         suma_iznad(a, n));
  printf("Suma ispod sporedne dijagonale je %.2f.\n",
         suma_ispod(a, n));

  return 0;
}
