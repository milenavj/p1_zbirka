#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_DUZINA 20
#define MAKS_NISKA (MAKS_DUZINA + 1)
#define MAKS_REZULTAT (2*MAKS_DUZINA + 1)

/* Funkcija od niske s formira rezultujucu nisku na sledeci nacin:
   1. Svi karakteri niske s koji su jednaki c1 se dupliraju. 2. Svi 
   karakteri niske s koji su jednaki c2 se brisu. 3. Ostali
   karakteri se samo prepisuju. */
void formiraj(char s[], char rezultat[], char c1, char c2) {
  int i, j;
  /* Brojac i se koristi za nisku s, a brojac j za rezultujucu
     nisku. */
  for (i = 0, j = 0; s[i]; i++) {
    if (s[i] == c1) {
      /* Ako je s[i] jednako c1, duplira se u rezultatu. */
      rezultat[j] = s[i];
      rezultat[j + 1] = s[i];
      j += 2;
    } else if (s[i] != c2) {
      /* Ako s[i] razlicito od c2, upisuje se u rezultat. */
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
  char c1, c2;

  /* Ucitavanje niske i karaktera. */
  printf("Unesite nisku: ");
  scanf("%s", s);
  getchar();
  printf("Unesite prvi karakter: ");
  scanf("%c", &c1);
  getchar();
  printf("Unesite drugi karakter: ");
  scanf("%c", &c2);

  /* Provera ispravnosti ulaza. */
  if (c1 == c2) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Racunanje i ispis rezultata. */
  formiraj(s, rezultat, c1, c2);
  printf("Rezultat: %s\n", rezultat);

  exit(EXIT_SUCCESS);
}
