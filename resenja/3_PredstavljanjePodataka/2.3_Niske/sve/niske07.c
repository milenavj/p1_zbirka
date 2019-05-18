#include <stdio.h>
#include <stdlib.h>

#define MAKS_NISKA 11

/* Funkcija proverava da li je niska t podniska niske s. */
int podniska(char s[], char t[]) {
  int i, j;

  /* Spoljasnja petlja ide redom po niski s. */
  for (i = 0; s[i] != '\0'; i++) {
    /* Unutrasnja petlja ide redom po niski t pomocu brojaca j i
       proverava da li se cela niska t poklapa sa delom niske s
       koji pocinje na poziciji i.

       Cim se naidje na situaciju da se karakteri ne poklapaju,
       izlazi se iz unutrasnje petlje. */
    for (j = 0; t[j] != '\0'; j++)
      if (s[i + j] != t[j])
        break;

    /* Ako je unutrasnja petlja dosla do kraja niske t, to znaci
       da su se svi karakteri iz t poklopili sa karakterima iz s i
       t je podniska od s. */
    if (t[j] == '\0')
      return 1;
  }
  return 0;
}


int main() {
  /* Deklaracija potrebnih promenljivih. */
  char s[MAKS_NISKA], t[MAKS_NISKA];

  /* Ucitavanje niski s i t. */
  printf("Unesite nisku s: ");
  scanf("%s", s);
  printf("Unesite nisku t: ");
  scanf("%s", t);

  /* Ispis rezultata. */
  if (podniska(s, t))
    printf("t je podniska niske s.\n");
  else
    printf("t nije podniska niske s.\n");

  /* II nacin: Funkcija strstr(t, s) proverava da li je t podniska 
     od s i kao povratnu vrednost vraca adresu prvog pojavljivanja
     t u s ili NULL ukoliko se t ne pojavljuje u s. Deklaracija
     ove funkcije se nalazi u zaglavlju string.h

     char* p = strstr(t, s); 
     if(p == NULL) 
       printf("t nije podniska od s.\n"); 
     else 
       printf("t je podniska od s.\n"); */

  exit(EXIT_SUCCESS);
}
