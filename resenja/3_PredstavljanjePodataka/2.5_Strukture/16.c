#include <stdio.h>
#include <ctype.h>

#define BROJ_SIFRI 100
#define BROJ_KARAKTERA 5000

/* Struktura koja opisuje sifru. */
typedef struct {
  int b;
  char smer;
} Sifra;

char sifruj(char c, Sifra s) {
  int pomeraj;

  if (!isalnum(c))
    return c;

  if (s.smer == 'L') {
    if (isdigit(c)) {
      pomeraj = s.b % 10;

      if (pomeraj > c - '0') {
        pomeraj = pomeraj - (c - '0') - 1;
        c = '9' - pomeraj;
      } else
        c = c - pomeraj;

      return c;
    }

    pomeraj = s.b % 26;

    if (islower(c)) {
      if (pomeraj > c - 'a') {
        pomeraj = pomeraj - (c - 'a') - 1;
        c = 'z' - pomeraj;
      } else
        c = c - pomeraj;

      return c;
    }

    if (pomeraj > c - 'A') {
      pomeraj = pomeraj - (c - 'A') - 1;
      c = 'Z' - pomeraj;
    } else
      c = c - pomeraj;

    return c;
  } else {
    if (isdigit(c)) {
      pomeraj = s.b % 10;

      if (pomeraj > '9' - c) {
        pomeraj = pomeraj - ('9' - c) - 1;
        c = '0' + pomeraj;
      } else
        c = c + pomeraj;

      return c;
    }

    pomeraj = s.b % 26;

    if (islower(c)) {
      if (pomeraj > 'z' - c) {
        pomeraj = pomeraj - ('z' - c) - 1;
        c = 'a' + pomeraj;
      } else
        c = c + pomeraj;

      return c;
    }

    if (pomeraj > 'Z' - c) {
      pomeraj = pomeraj - ('Z' - c) - 1;
      c = 'A' + pomeraj;
    } else
      c = c + pomeraj;

    return c;
  }
}

int main() {
  char linija[BROJ_KARAKTERA];
  Sifra sifre[BROJ_SIFRI];
  char c;
  int n = 0, j = 0, i;

  printf("Uneti sifre u obliku: broj, smer:\n");
  while (scanf("%d %c", &sifre[n].b, &sifre[n].smer) != EOF) {
    if (sifre[n].smer != 'L' && sifre[n].smer != 'D') {
      printf("Neispravan smer.\n");
      return -1;
    }

    if (sifre[n].b < 0) {
      printf("Neispravan broj za sifrovanje.\n");
      return -1;
    }

    n++;
    if (n == BROJ_SIFRI)
      break;
  }

  printf("Uneti tekst za sifrovanje:\n");
  while ((c = getchar()) != EOF) {
    for (i = 0; i < n; i++)
      c = sifruj(c, sifre[i]);

    linija[j] = c;
    j++;

    if (j == BROJ_KARAKTERA)
      break;
  }

  linija[j] = 0;

  printf("%s\n", linija);

  return 0;
}
