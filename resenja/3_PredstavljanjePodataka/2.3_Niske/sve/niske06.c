#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_NISKA 21

/* Funkcija koja vraca indeks prvog pojavljivanja karaktera c u
   okviru niske s. Ukoliko se ne pojavljuje, funkcija vraca -1. */
int pozicija(char s[], char c)
{
  int i;
  
  for(i=0; s[i]; i++)
    if(s[i] == c)
      return i;
    
  return -1;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA];
  char c;

  /* Ucitavaju se niska i karakter. */
  printf("Unesite nisku:");
  scanf("%s", s);
  getchar();
  printf("Unesite karakter:");
  c = getchar();

  /* I nacin: */
   printf("%d\n", pozicija(s,c));

  /* II nacin:
     Funkcija strchr(s,c) je funkcija koja vraca adresu prvog
     pojavljivanja karaktera c u niski s, ako se c pojavljuje u s, 
     a NULL inace.

     Vrednost promenljive s je zapravo vrednost adrese prvog
     karaktera niske s.
     
     Ako treba da se ispise indeks prvog pojavljivanja, to moze
     da se uradi tako sto se od adrese koji je vratila funkcija 
     strchr oduzme adresa prvog karaktera.
     
     Na primer: 
     s = "koliba"     ==> s je adresa karaktera 'k'
     p = strchr(s, 'l') ==> p je adresa karaktera 'l'
     |k|o|l|i|b|a|
      ^   ^
      |   |
      s   p
     Izraz p-s ima vrednost 2 (jer je rastojanje izmedju 
     ove dve adrese 2). 

     Tip promenljive p je char* jer predstavlja adresu 
     jednog karaktera.
     
  char *p = strchr(s, c);
  if (p != NULL)
    printf("%d\n", p - s);
  else
    printf("-1\n");
  */

  exit(EXIT_SUCCESS);
}
