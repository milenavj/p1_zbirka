#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija obrce nisku s. */
void obrni(char s[])
{
  int i, j;
  int n = strlen(s);
  char c;
  
  /* Brojac i ide od prvog karaktera niske s, a brojac j
     od poslednjeg i dok god se ne sretnu, vrsi se zamena
     karaktera koji se nalaze na njihovim pozicijama. */
  for(i=0, j=n-1; i<j; i++,j--)
  {
      c = s[i];
      s[i] = s[j];
      s[j] = c;
  }
}

int main()
{
  /* Deklaracija niske. */
  char s[MAKS_NISKA];
  
  /* Ucitava se niska. */
  printf("Unesite nisku: ");
  scanf("%s", s);
  
  /* Racunanje i ispis rezultata. */
  obrni(s);
  printf("%s\n", s);
  
  exit(EXIT_SUCCESS);
}