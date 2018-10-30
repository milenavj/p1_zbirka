#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define DUZINA_ALFABETA 26

/* Funkcija za ispis elemenata niza. */
void ispis(int niz[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%c:%d  ", 'a' + i, niz[i]);
  putchar('\n');
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int mala_slova[DUZINA_ALFABETA];
  int c, i;

  /* Inicijalizacija niza brojaca na nule. */
  for (i = 0; i < DUZINA_ALFABETA; i++)
    mala_slova[i] = 0;

  /* Ucitavaju se karakteri sve do kraja ulaza. */
  while ((c = getchar()) != EOF) {
    /* Ako je procitani karakter slovo broj pojavljivanja slova se
       uvecava. Kako se zanemaruje velicina slova, svako slovo se
       pretvori u malo i potom se element na odgovarajucoj poziciji 
       u nizu uveca. */
    if (isalpha(c))
      mala_slova[tolower(c) - 'a']++;
  }

  /* Ispis rezultata. */
  ispis(mala_slova, DUZINA_ALFABETA);

  exit(EXIT_SUCCESS);
}
