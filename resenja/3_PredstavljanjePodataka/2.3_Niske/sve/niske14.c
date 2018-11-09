#include <stdio.h>
#include <stdlib.h>

/* Duzina niske koja se ucitava, bez terminalne nule. */
#define MAKS_DUZINA 20

/* Duzine originalne i rezultujuce niske. */
#define MAKS_NISKA (MAKS_DUZINA + 1)
#define MAKS_REZULTAT (2 * MAKS_DUZINA + 1)

/* Funkcija koja od niske s formira nisku t dupliranjem svakog
   karaktera. Npr. abc postaje aabbcc. */
void dupliranje(char t[], char s[])
{
  int i, j;

  /* Brojac i oznacava tekucu poziciju u niski s, a
     brojac j oznacava tekucu poziciju u niski t. */
  for (i = 0, j = 0; s[i] != '\0'; i++, j += 2) {
    t[j] = s[i];
    t[j + 1] = s[i];
  }

  /* Upisuje se terminalna nula na kraj rezultujuce niske. */
  t[j] = '\0';
}

int main()
{
  /* Deklaracija niski. */
  char s[MAKS_NISKA], t[MAKS_REZULTAT];

  /* Ucitava se niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Poziva se funkcija za dupliranje. */
  dupliranje(t, s);

  /* Ispis rezultata. */
  printf("%s\n", t);

  exit(EXIT_SUCCESS);
}
