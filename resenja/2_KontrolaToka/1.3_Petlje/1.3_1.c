#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenlijvih. */
  int i;

  /* Promenljiva i kontrolise koliko puta ce se petlja izvrsiti i
     naziva se brojac petlje. Njena pocetna vrednost se postavlja na 
     0 jer se u pocetku petlja nije ni jednom izvrsila. */
  i = 0;
  
  /* Petlja ce se izvrsiti za i=0,1,2,3,4. Kada i dostigne vrednost
     5 uslov i < 5 nece biti ispunjen i prelazi se na prvu sledecu
     naredbu nakon tela petlje. */
  while (i < 5) { 

    /* Ispis poruke. */
    printf("Mi volimo da programiramo.\n");

    /* Uvecavanje brojaca za 1. */
    i++;
  }

  return 0;
}
