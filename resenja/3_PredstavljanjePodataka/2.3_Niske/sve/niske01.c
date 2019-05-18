#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/* Poslednji karakter svake niske je terminirajuca nula '\0',
   specijalni karakter ciji je ASCII kod 0.

   Ukoliko je pretpostavka da niska sadrzi najvise 10 karaktera,
   neophodno je deklarisati niz od 11 karaktera, pri cemu se
   dodatni karakter izdvaja za terminirajucu nulu. */
#define MAKS_NISKA 11

/* Funkcija vrsi konverziju svakog malog slova niske u odgovarajuce
   veliko slovo i obrnuto. Ostali karakteri ostaju nepromenjeni. */
void konvertuj(char s[]) {
  int i;

  /* Prolazi se kroz nisku, karakter po karakter, sve dok se ne
     dodje do terminirajuce nule koja sluzi kao oznaka kraja niske. */
  for (i = 0; s[i] != '\0'; i++) {
    /* Svako malo slovo se pretvara u veliko i obrnuto. */
    if (islower(s[i]))
      s[i] = toupper(s[i]);
    else if (isupper(s[i]))
      s[i] = tolower(s[i]);
  }

  /* II nacin: Uslov u petlji moze krace da se zapise sa s[i] jer
     ASCII kod terminirajuce nule ima vrednost 0. for (i = 0; s[i];
     i++) { if (islower(s[i])) s[i] = toupper(s[i]); else if
     (isupper(s[i])) s[i] = tolower(s[i]); } */
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_NISKA];
  
  /* Za razliku od nizova koji se ucitavaju i stampaju element po
     element, niske se mogu ucitati i odstampati pomocu jedne
     scanf/printf naredbe koriscenjem specifikatora %s. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Izmena niske. */
  konvertuj(s);

  /* Ispis rezultata. */
  printf("%s\n", s);

  exit(EXIT_SUCCESS);
}
