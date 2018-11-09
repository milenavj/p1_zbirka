#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija koja racuna duzinu prefiksa niske t koji se moze 
   zapisati pomocu karaktera niske s. 
   Na primer, t="programiranje", s="grupacija", rezultat je 2 jer
   niska s sadrzi prva dva karaktera niske t, ali ne i treci. */
int strspn_klon(char t[], char s[])
{
  int i, brojac = 0;
  
  /* Ide se redom po karakterima niske t i za svaki karakter se
     vrsi provera da li se on nalazi u zapisu niske s. Za ovo se
     koristi funkcija strchr. Ako se nalazi, uvecava se brojac,
     a ako se ne nalazi, prekida se petlja. */
  for(i=0; t[i]; i++){
    if(strchr(s, t[i]) != NULL)
      brojac++;
    else
      break;
  }
  
  return brojac;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  char s[MAKS_NISKA];
  char t[MAKS_NISKA];
  
  /* Ucitavaju se niske. */
  printf("Unesite nisku t: ");
  scanf("%s", t);
  printf("Unesite nisku s: ");
  scanf("%s", s);
  
  /* Racunanje i ispis rezultata. */
  printf("%d\n", strspn_klon(t,s));
  
  exit(EXIT_SUCCESS);
}