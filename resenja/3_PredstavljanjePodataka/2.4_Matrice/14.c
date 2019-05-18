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

/* Funkcija racuna sumu kolone j. */
int suma_kolone(int a[][MAKS], int n, int j) {
  int i, suma = 0;

  for (i = 0; i < n; i++)
    suma += a[i][j];

  return suma;
}

/* Funkcija racuna sumu i-te vrste. */
int suma_vrste(int a[][MAKS], int n, int i) {
  int j, suma = 0;

  for (j = 0; j < n; j++)
    suma += a[i][j];

  return suma;
}

/* Funkcija proverava da li elementi matrice predstavljaju magicni
   kvadrat. */
int magicni_kvadrat(int a[][MAKS], int n) {
  /* Da bi matrica bila magicni kvadrat, sume svih vrsta i kolona
     treba da budu jednke. Suma se zato inicijalizuje na sumu prve
     kolone. */
  int suma = suma_kolone(a, n, 0);
  int i, j;

  /* Proverava se da li su sume ostalih kolona jednake izracunatoj
     sumi. Ukoliko se naidje na kolonu koja ne zadovoljava ovaj
     uslov, matrica nije magicni kvadrat. */
  for (j = 1; j < n; j++)
    if (suma_kolone(a, n, j) != suma)
      return 0;

  /* Proverava se i da li su sume svih vrsta jednake izracunatoj
     sumi. Ukoliko se naidje na vrstu koja ne zadovoljava ovaj
     uslov, matrica nije magicni kvadrat. */
  for (i = 0; i < n; i++)
    if (suma_vrste(a, n, i) != suma)
      return 0;

  /* Ako sve vrste i kolone imaju jednake sume, matrica je magicni
     kvadrat. */
  return 1;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
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
  if (magicni_kvadrat(a, n))
    printf("Matrica jeste magicni kvadrat.\n");
  else
    printf("Matrica nije magicni kvadrat.\n");

  return 0;
}
