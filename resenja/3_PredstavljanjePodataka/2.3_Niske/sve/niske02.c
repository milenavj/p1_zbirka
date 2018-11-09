#include <stdio.h>
#include <stdlib.h>

#define MAKS_NISKA 31

/* Funkcija koja ubacuje zvezdice na svako drugo mesto
   niske s. */
void ubaci_zvezdice(char s[]){
  int i;
  
  for(i=0; s[i] != '\0' && s[i+1] != '\0'; i+=2)
    s[i+1] = '*';
  
  /* Uslov u petlji moze krace da se zapise na sledeci nacin: 
   for(i=0; s[i] && s[i+1]; i+=2)
    s[i+1] = '*';
   */
  
  /* III nacin: 
   for(i=0; s[i]; i++)
     if(i%2 == 1)
      s[i] = '*';
   */
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA];
  
  /* Ucitavanje niske. */
  printf("Unesite nisku: ");
  scanf("%s", s);
  
  /* Izmena niske. */
  ubaci_zvezdice(s);
  
  /* Ispis rezultata. */
  printf("Izmenjena niska: %s\n", s);
  
  exit(EXIT_SUCCESS);
}