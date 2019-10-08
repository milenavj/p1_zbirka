/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_NISKA 21

/* Funkcija proverava da li niska s sadrzi bar jedno veliko slovo. */
int sadrzi_veliko(char s[]) {
  int i;

  for (i = 0; s[i]; i++)
    if (isupper(s[i]))
      return 1;

  return 0;

  /* Cesta greska: 
     for(i=0; s[i]; i++) { 
       if(isupper(s[i])) 
         return 1; 
       else 
         return 0; 
     } 
     Cim se naidje na prvi karakter koji nije
     veliko slovo, vraca se 0 kao oznaka da niska ne sadrzi veliko
     slovo, sto nije tacno. Nula moze da se vrati tek kada se
     prodju svi karakteri niske s. */
}

int main() {
  /* Deklaracija potrebne promenljive. */
  char s[MAKS_NISKA];

  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);

  /* Ispis rezultata. */
  if (sadrzi_veliko(s))
    printf("Sadrzi veliko slovo.\n");
  else
    printf("Ne sadrzi veliko slovo.\n");

  exit(EXIT_SUCCESS);
}
