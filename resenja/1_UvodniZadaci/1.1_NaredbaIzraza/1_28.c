#include <stdio.h>
#include <math.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int x, p, c;
  unsigned int levo, desno;
  unsigned int novo_x;

  /* Ucitavaju se broj, pozicija i cifra. */
  printf("Unesite redom x, p i c: ");
  scanf("%u%u%u", &x, &p, &c);

  /* Racuna se deo broja koji se nalazi desno od pozicije p. 
     Funkcija pow kao povratnu vrednost vraca realan broj dvostruke tacnosti, a operacija % ocekuje celobrojne operande. Iz tog razloga je neophodno izvrsiti pretvaranje povratne vrednosti u tip unsigned int. */
  desno = x % (unsigned int) pow(10, p);

  /* Racuna se deo broja koji se nalazi levo od pozicije p. */
  levo = x / (unsigned int) pow(10, p);

  /* Rezultat se racuna nadovezivanjem levog dela, cifre c i desnog dela. */
  novo_x =levo * (unsigned int) pow(10, p + 1) + 
         c * (unsigned int) pow(10, p) + desno;

  /* Ispis rezultata. */
  printf("Rezultat je: %u\n", novo_x);

  return 0;

}
