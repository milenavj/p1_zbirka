#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija proverava da li je karakter c samoglasnik. */
int samoglasnik(char c)
{
  /* Karakter se pretvara u veliko slovo kako bi se izbegle posebne
     provere za mala i velika slova. */
  c = toupper(c);

  /* Samoglasnici su slova a, e, i, o i u */
  if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
    return 1;

  return 0;
}

/* Funkcija proverava da li se niska s zavrsava samoglasnikom. */
int samoglasnik_na_kraju(char s[])
{
  /* Funkcija strlen racuna duzinu date niske. Njena deklaracija se 
     nalazi u zaglavlju string.h. */
  int duzina = strlen(s);

  /* Ako je niska prazna, ne zavrsava se samoglasnikom. */
  if (duzina == 0)
    return 0;

  /* Proverava se da li je poslednji karakter niske samoglasnik. */
  return samoglasnik(s[duzina - 1]);
}

int main()
{
  /* Deklaracija niske. */
  char s[MAKS_NISKA];

  /* Ucitava se niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ispis rezultata. */
  if (samoglasnik_na_kraju(s))
    printf("Niska se zavrsava samoglasnikom.\n");
  else
    printf("Niska se ne zavrsava samoglasnikom.\n");

  exit(EXIT_SUCCESS);
}
