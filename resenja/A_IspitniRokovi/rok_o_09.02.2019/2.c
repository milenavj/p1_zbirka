#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 21

/* Funkcija ispisuje odgovarajucu poruku na standardni izlaz za
   greske i prekida izvrsavanje programa. */
void greska() {
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char s[MAX];
  char novo_s[MAX];
  int n;

  /* Ucitavanje niske. */
  scanf("%s", s);

  /* Provera duzine ucitane niske. */
  n = strlen(s);
  if (n % 2 != 0) {
    greska();
  }

  /* Popunjavanje nove niske nulama. */
  memset(novo_s, '\0', sizeof(n));

  /* Kopiranje druge polovine niske s u novu nisku. */
  strcpy(novo_s, s + n / 2);

  /* Kopiranje prve polovine niske s u novu nisku. */
  s[n / 2] = 0;
  strcpy(novo_s + n / 2, s);

  /* Ispis rezultata. */
  printf("%s\n", novo_s);

  exit(EXIT_SUCCESS);
}
