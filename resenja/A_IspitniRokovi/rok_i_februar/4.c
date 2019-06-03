#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_BROJ_STUDENATA 100
#define MAX_UCIONICA 11

/* Struktura koja opisuje studenta. */
typedef struct {
  int indeks;
  double poeni;
  char ucionica[MAX_UCIONICA];
} STUDENT;

int main() {
  /* Deklaracija potrebnih promenljivih. */
  STUDENT studenti[MAX_BROJ_STUDENATA];
  int i, n, broj_studenata;
  char ucionica[MAX_UCIONICA];

  /* Ucitavanje broja studenata i provera ispravnosti unosa. */
  scanf("%d", &n);
  if (n <= 0 || n > MAX_BROJ_STUDENATA) {
    printf("-1\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o studentima. */
  for (i = 0; i < n; i++) {
    scanf("%d%lf%s", &studenti[i].indeks, &studenti[i].poeni,
          studenti[i].ucionica);
  }

  /* Ucitavanje oznake ucionice i provera ispravnosti unosa. */
  scanf("%s", ucionica);
  if (strcmp(ucionica, "704") && strcmp(ucionica, "718") &&
      strcmp(ucionica, "bim") && strcmp(ucionica, "rlab")) {
    printf("-1\n");
    exit(EXIT_FAILURE);
  }

  /* Odredjivanje broja studenata koji su polagali ispit u zadatoj
     ucionici i polozili ga. */
  broj_studenata = 0;
  for (i = 0; i < n; i++) {
    if (!strcmp(ucionica, studenti[i].ucionica)
        && studenti[i].poeni >= 51.0) {
      broj_studenata++;
    }
  }

  /* Ispis rezultata. */
  printf("%d\n", broj_studenata);

  exit(EXIT_SUCCESS);
}
