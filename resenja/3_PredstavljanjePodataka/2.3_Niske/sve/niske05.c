#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_NISKA 21

/* Funkcija koja proverava da li niska s sadrzi bas jedno
   veliko slovo. */
int sadrzi_veliko(char s[])
{
  int i;
  
  for(i=0; s[i]; i++)
    if(isupper(s[i]))
      return 1;
    
  return 0;
}

int main()
{
  /* Deklaracija niske. */
  char s[MAKS_NISKA];

  /* Ucitava se niska. */
  printf("Unesite nisku:");
  scanf("%s", s);

  /* Ispis rezultata. */
  if(sadrzi_veliko(s))
    printf("Sadrzi veliko slovo.\n");
  else
    printf("Ne sadrzi veliko slovo.\n");

  exit(EXIT_SUCCESS);
}
