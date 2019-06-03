#include <stdio.h>
#include <stdlib.h>

#define MAX 101

/* Funkcija koja izracunava zbir elemenata na glavnoj dijagonali
   kvadratne matrice dimenzije n. */
int suma(int m[][MAX], int n) {
  int i, s = 0;

  for (i = 0; i < n; i++) {
    s += m[i][i];
  }

  return s;
}

/* Funkcija koja izracunava vrednost najmanjeg elementa glavne
   dijagonale kvadratne matrice dimenzije n. */
int minimum(int m[][MAX], int n) {
  int i;
  int min = m[0][0];

  for (i = 1; i < n; i++) {
    if (min > m[i][i]) {
      min = m[i][i];
    }
  }

  return min;
}

/* Funkcija koja izracunava vrednost najveceg elementa glavne
   dijagonale kavdratne matrice dimenzije n. */
int maximum(int m[][MAX], int n) {
  int i;
  int max = m[0][0];

  for (i = 1; i < n; i++) {
    if (max < m[i][i]) {
      max = m[i][i];
    }
  }

  return max;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int m[MAX][MAX], n, i, j;

  /* Ucitavanje dimenzije matrice i provera ispravnosti unosa. */
  scanf("%d", &n);
  if (n <= 0 || n > MAX || n % 2 == 0) {
    printf("-1\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata matrice. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      scanf("%d", &m[i][j]);
    }
  }

  /* Provera da li je suma elemenata na glavnoj dijagonali matrice
     parna. */
  if (suma(m, n) % 2) {
    /* Ako jeste, ispisuje se vrednost maksimalnog elementa
       dijagonale. */
    printf("%d\n", maximum(m, n));
  } else {
    /* U suprotnom se ispisuje vrednost minimalnog elementa
       dijagonale. */
    printf("%d\n", minimum(m, n));
  }

  exit(EXIT_SUCCESS);
}
