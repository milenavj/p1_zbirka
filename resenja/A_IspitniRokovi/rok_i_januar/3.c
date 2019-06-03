#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, m, i, j, redni_broj_pobednika;
  float trke[MAX][MAX], pobednik;

  /* Ucitavanje broja takmicara i broja trka. */
  scanf("%d%d", &n, &m);

  /* Provera ispravnosti ucitanih vrednosti. */
  if (n < 3 || n > MAX || m < 2 || m > MAX) {
    printf("-1\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje vremena takmicara po trkama. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < m; j++) {
      scanf("%f", &trke[i][j]);

      /* Provera da li je zadato korektno vreme. */
      if (trke[i][j] <= 0.0) {
        printf("-1\n");
        exit(EXIT_FAILURE);
      }
    }
  }

  /* Odredjivanje pobednika u trkama. */
  for (j = 0; j < m; j++) {
    
    /* Odredjivanje pobednika j-te trke se svodi na problem
       pronalazenje minimuma j-te kolone. */
    pobednik = trke[0][j];
    redni_broj_pobednika = 0;

    for (i = 1; i < n; i++) {
      if (pobednik > trke[i][j]) {
        pobednik = trke[i][j];
        redni_broj_pobednika = i;
      }
    }

    printf("%d ", redni_broj_pobednika);
  }

  printf("\n");

  return 0;
}
