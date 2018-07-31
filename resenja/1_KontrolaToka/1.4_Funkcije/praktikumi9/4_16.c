#include <stdio.h>
#include <stdlib.h>

 * 
 * Interesantna situacija je ukoliko su dve uzastopne cifre
 * obe parne, odnosno obe neparne.
 * Ovaj uslov svodimo na poredjenje njihovih ostataka pri deljenju sa 2:
 * ukoliko su ostaci isti, cifre su iste parnosti,
 * te ne treba dalje proverati da li je uslov zadovoljen,
 * vec odmah prekinuti sa izvrsavanjem funkcije.
 * 
 * Ukoliko dve uzastopne cifre ni u jednom slucaju nisu bile iste parnosti,
 * a izdvojene su sve cifre iz broja x,
 * uslov je ispunjen, pa funkcija vraca 1.
 */

/* Funkcija proverava da li su dve uzastopne cifre razlicite parnosti. */
int par_nepar(int x) {
  /* Dve uzastopne cifre broja se pamte u promenljivama prethodna_cifra i tekuca_cifra. */
  int prethodna_cifra;
  int tekuca_cifra;
  
  /* U slucaju da je uneti broj negativan posmatra se samo apsolutna vrednost. */
  x = abs(x);
  
  /* Poslednja cifra broja se izdvaja van petlje da bi u petlji moglo da se vrsi poredjenje. */
  prethodna_cifra = x % 10;
  x /= 10;
  
  while(x) {
    /* Izdvaja se cifra broja. */
    tekuca_cifra = x % 10;
    
	 /* Ukoliko su uzastopne cifre iste parnosti, uslov nije ispunjen, rad petlje i funkcije se prekida i vraca se 0. */
    if(tekuca_cifra % 2 == prethodna_cifra % 2)
      return 0;
    
    /* Tekuca cifra postaje prethodna cifra za narednu iteraciju. */
    prethodna_cifra = tekuca_cifra;
    x /= 10;
  }
  
  /* Sve uzastopne cifre su razlicite parnosti jer ni jednom u petlji uslov da su cifre iste parnosti nije bio ispunjen. */
  return 1;
}

int main() {

  int x;
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  if(par_nepar(x))
    printf("Broj ispunjava uslov!\n");
  else
    printf("Broj ne ispunjava uslov!\n");
  
  return 0;
}
