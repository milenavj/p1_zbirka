#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_DUZINA 20
#define MAKS_NISKA (MAKS_DUZINA + 1)
#define MAKS_REZULTAT (3*MAKS_DUZINA + 1)

/* Pomocna funkcija koja za prosledjeno slovo vraca slovo koje ide
   posle njega. */
char sledeci(char c) {
  if (c == 'z')
    return 'a';

  if (c == 'Z')
    return 'A';

  return c + 1;
}

/* Funkcija od niske s formira rezultujucu nisku koja se dobija na
   sledeci nacin: 
   1. ako je s[i] slovo, onda se u rezultujucu nisku upisuju naredna
   tri slova alfabeta (kada se stigne do kraja alfabeta, ide se u 
   krug, tj. nakon slova z sledi slovo a)
   2. ako s[i] nije slovo, s[i] se samo prepisuje u rezultat. */
void sifruj(char s[], char rezultat[]) {
  int i, j;

  /* Brojac i se koristi za nisku s, a brojac j za rezultujucu
     nisku. */
  for (i = 0, j = 0; s[i]; i++) {
    if (isalpha(s[i])) {
      /* Ako je s[i] slovo, onda se u rezultat upisuju 3 slova koja
         slede nakon njega. */
      rezultat[j] = sledeci(s[i]);
      rezultat[j + 1] = sledeci(rezultat[j]);
      rezultat[j + 2] = sledeci(rezultat[j + 1]);
      j += 3;
    } else {
      /* Ako s[i] nije slovo, onda se samo prepisuje u rezultat. */
      rezultat[j] = s[i];
      j++;
    }
  }

  /* Na kraj rezultata se dopisuje terminirajuca nula. */
  rezultat[j] = '\0';
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA], rezultat[MAKS_REZULTAT];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Racunanje i ispis rezultata. */
  sifruj(s, rezultat);
  printf("Rezultat: %s\n", rezultat);

  exit(EXIT_SUCCESS);
}
