#include <stdio.h>
#include <stdlib.h>

/* Funkcija proverava da li su dve uzastopne cifre
 * razlicite parnosti.
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
int par_nepar(int x) {

  int prethodna_cifra;
  int tekuca_cifra;
  
  /* u slucaju da je uneti broj negativan */
  x = abs(x);
  
  /* jednu cifru izdvajamo van petlje
   * kako bismo mogli da je odmah u petlji poredimo sa narednom 
   */
  prethodna_cifra = x % 10;
  x /= 10;
  
  while(x) {
  
    tekuca_cifra = x % 10;
    
    if(tekuca_cifra % 2 == prethodna_cifra % 2)
      return 0;
    
    /* tekuca cifra postaje prethodna cifra za narednu iteraciju */
    prethodna_cifra = tekuca_cifra;
    x /= 10;
  }
  
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