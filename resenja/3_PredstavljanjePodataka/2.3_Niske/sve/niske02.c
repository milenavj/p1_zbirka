#include <stdio.h>
#include <stdlib.h>

#define MAKS_NISKA 21

/* Funkcija ubacuje zvezdice na svako drugo mesto niske s. */
void ubaci_zvezdice(char s[]) {
  int i;

  for (i = 0; s[i] != '\0' && s[i + 1] != '\0'; i += 2)
    s[i + 1] = '*';
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_NISKA];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Izmena niske. */
  ubaci_zvezdice(s);

  /* Ispis rezultata. */
  printf("Izmenjena niska: %s\n", s);

  exit(EXIT_SUCCESS);
}
