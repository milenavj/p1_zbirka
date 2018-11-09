#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_NISKA 11

/* Funkcija koja svako malo slovo niske pretvara u odgovarajuce
   veliko i obrnuto. Ostali karakteri ostaju nepromenjeni. */
void konvertuj(char s[])
{
  int i;

  /* Prolazi se kroz nisku, karakter po karakter, sve dok se ne
     dodje do terminalne nule koja sluzi kao oznaka da se doslo
     do kraja niske. */
  for (i = 0; s[i] != '\0'; i++)
  {
    /* Svako malo slovo se pretvara u veliko i obrnuto. */
    if (islower(s[i]))
      s[i] = toupper(s[i]);
    else if (isupper(s[i]))
      s[i] = tolower(s[i]); 
  }
}

int main()
{
  /* Poslednji karakter svake niske je terminirajuca nula '\0',
     specijalni karakter ciji je ASCII kod 0.
     
     Ukoliko je pretpostavka da niska sadrzi najvise 10 karaktera, 
     neophodno je deklarisati niz od 11 karaktera, pri cemu se
     dodatni izdvaja za terminirajucu nulu. */
  char s[MAKS_NISKA];
  printf("Unesite nisku: ");

  /* Za razliku od nizova koji se ucitavaju i stampaju element po
     element, niske se mogu ucitati i odstampati pomocu jedne
     scanf/printf naredbe koriscenjem specifikatora %s. */
  scanf("%s", s);

  /* Izmena niske. */
  konvertuj(s);

  /* Ispis rezultata. */
  printf("%s\n", s);

  exit(EXIT_SUCCESS);
}
