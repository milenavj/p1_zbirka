#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_NISKA 21

/* Funkcija svako slovo niske s menja sa slovom koje se u ASCII
   tablici nalazi neposredno iza njega. Specijalan slucaj je slovo
   z koje treba da se zameni slovom a. Ostali karakteri ostaju
   nepromenjeni. */
void sifruj(char s[]) {
  int i;

  for (i = 0; s[i]; i++)
    if (isalpha(s[i])) {
      if (s[i] == 'z')
        s[i] = 'a';
      else if (s[i] == 'Z')
        s[i] = 'A';
      else
        s[i] = s[i] + 1;
    }
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_NISKA];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Racunanje i ispis rezultata. */
  sifruj(s);
  printf("Rezultat: %s\n", s);

  exit(EXIT_SUCCESS);
}
