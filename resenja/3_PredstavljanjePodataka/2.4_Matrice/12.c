#include <stdio.h>
#include <stdlib.h>

#define MAKS 10

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

/* Funkcija racuna sumu elemenata kolone j. */
int suma_kolone(int a[][MAKS], int n, int j) {
  int suma = 0, i;

  for (i = 0; i < n; i++)
    suma += a[i][j];

  return suma;
}

/* Funkcija proverava da li su sume kolona uredjene rastuce i vraca 
   jedinicu ako jesu, a nulu inace. */
int uredjene_sume(int a[][MAKS], int n) {
  int prethodna_suma, trenutna_suma, j;

  /* Prva suma se inicijalizuje na sumu prve kolone. */
  prethodna_suma = suma_kolone(a, n, 0);

  for (j = 1; j < n; j++) {
    /* Racunanje sume trenutne kolone. */
    trenutna_suma = suma_kolone(a, n, j);

    /* Ukoliko je ta suma manja ili jednaka prethodnoj, poredak
       suma nije rastuci. */
    if (trenutna_suma <= prethodna_suma)
      return 0;

    /* Suma trenutne kolone postaje suma prethodne kolone za
       narednu iteraciju. */
    prethodna_suma = trenutna_suma;
  }

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
  if (uredjene_sume(a, n))
    printf("Sume jesu uredjenje strogo rastuce.\n");
  else
    printf("Sume nisu uredjenje strogo rastuce.\n");

  return 0;
}
