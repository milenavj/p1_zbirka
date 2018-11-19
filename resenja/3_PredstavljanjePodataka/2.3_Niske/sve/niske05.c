#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_NISKA 21

/* Funkcija proverava da li niska s sadrzi bar jedno
   veliko slovo. */
int sadrzi_veliko(char s[])
{
  int i;
  
  for(i=0; s[i]; i++)
    if(isupper(s[i]))
      return 1;
    
  return 0;
  
  /* Cesta greska:
       for(i=0; s[i]; i++)
       {
          if(isupper(s[i]))
            return 1;
          else 
            return 0;
       }
     Cim se naidje na prvi karakter koji nije veliko
     slovo, vraca se 0 kao oznaka da niska ne sadrzi
     veliko slovo, sto nije tacno. Nula moze da se vrati
     tek kada se prodju svi karakteri niske s. */
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
