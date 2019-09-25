#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente matrice dimenzije mxn. */
void ucitaj(int a[][MAKS], int n) {
  int i, j;
  printf("Unesite elemente matrice:\n");
  for (i = 0; i < n; i++)
    for (j = 0; j < n; j++)
      scanf("%d", &a[i][j]);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS][MAKS];
  int n, i, j, k;

  /* Ucitavanje dimenzije matrice i provera ispravnosti ulaza. */
  printf("Unesite broj vrsta matrice: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  ucitaj(a, n);

  /* Petlja kojom se ispisuju dijagonale iznad sporedne dijagonale, 
     ukljucujuci i sporednu dijagonalu. 
     Npr. za n=4, indeksi elemenata u matrici su: 
     (0,0) (0,1) (0,2) (0,3) 
     (1,0) (1,1) (1,2) (1,3) 
     (2,0) (2,1) (2,2) (2,3) 
     (3,0) (3,1) (3,2) (3,3)
     Dakle, ispis elemenata ide u sledecem redosledu: 
     (0,0) 
     (0,1) (1,0) 
     (0,2) (1,1) (2,0) 
     (0,3) (1,2) (2,1) (3,0) 
     Za k-ti ispis vazi da indeksi vrsta imaju vrednosti od nula do
     k, a indeksi kolona od k do nula. */
  printf("Ispis je:\n");
  for (k = 0; k < n; k++) {
    /* Indeks kolone se inicijalizuje na k, a indeks vrste na 0. */
    j = k;
    i = 0;

    /* Ispisuju se odgovarajuci elementi, indeks vrste se povecava,
       a indeks kolone se smanjuje. */
    while (j >= 0) {
      printf("%d ", a[i][j]);
      i++;
      j--;
    }
    printf("\n");
  }

  /* Petlja kojom se ispisuju dijagonale ispod sporedne dijagonale.
     Npr. za n=4, indeksi elemenata u matrici su: 
     (0,0) (0,1) (0,2) (0,3) 
     (1,0) (1,1) (1,2) (1,3) 
     (2,0) (2,1) (2,2) (2,3) 
     (3,0) (3,1) (3,2) (3,3) 
     Dakle, ispis elemenata ide u sledecem redosledu: 
     (1,3) (2,2) (3,1) 
     (2,3) (3,2)
     (3,3) 
     Za k-ti ispis vazi da indeksi vrsta imaju vrednosti od k do
     n-1, a indeksi kolona od n-1 do 1. */
  for (k = 1; k < n; k++) {
    i = k;
    j = n - 1;

    while (i < n) {
      printf("%d ", a[i][j]);
      i++;
      j--;
    }
    printf("\n");
  }

  return 0;
}
