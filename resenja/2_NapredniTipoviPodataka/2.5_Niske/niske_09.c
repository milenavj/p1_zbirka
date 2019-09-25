#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_LINIJA 21

/* Funkcija uklanja sva slova iz niske s. */
void ukloni_slova(char s[]) {
  int i, j;

  /* Prolazi se kroz nisku s karakter po karakter i vrsi se provera
     da li trenutni karakter treba da se zadrzi. Karakter treba da
     se zadrzi ukoliko nije ni malo ni veliko slovo.

     Brojac j sluzi da pamti gde se upisuje sledeci karakter koji
     treba da se zadrzi i svaki put kada se naidje na takav karaker,
     on se upisuje na poziciju j, a brojac j se uvecava. */
  for (i = 0, j = 0; s[i]; i++)
    if (!islower(s[i]) && !isupper(s[i])) {
      s[j] = s[i];
      j++;
    }

  /* Na kraju se na poziciji j upisuje i terminirajuca nula, kako bi
     se naznacilo da se kraj niske nalazi nakon poslednjeg
     zadrzanog karaktera. */
  s[j] = '\0';
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_LINIJA];

  /* Ucitavanje niske s. */
  printf("Unesite nisku:\n");
  scanf("%s", s);

  /* Ispis rezultata. */
  ukloni_slova(s);
  printf("Rezultat: %s\n", s);

  exit(EXIT_SUCCESS);
}
