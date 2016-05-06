#include <stdio.h>
#include <stdlib.h>

/* Funkcija proverava da li se
 * cifre u zapisu broja nalaze u rastucem poretku.
 * 
 * Situacija od interesa je kada za dve uzastopne cifre to nije slucaj.
 * Tada ne treba proveravati i za ostale cifre,
 * vec odmah prekinuti izvrsavanje funkcije.
 * 
 * Ukoliko funkcija nije ranije prekinuta,
 * to znaci da cifre jesu u rastucem poretku
 * (odnosno, kako izdvajamo cifre od nazad, u stvari proveravamo opadajuci poredak),
 * te treba vratiti 1.
 */

int rastuce(int n) {

  int tekuca_cifra;
  int prethodna_cifra;
  
  n = abs(n);
  
  /* Prvu cifru (odnosno, poslednju u zapisu broja) 
   * izdvajamo izvan petlje
   * kako bismo mogli da je poredimo sa narednom 
   */
  tekuca_cifra = n % 10;
  n /= 10;
  
  while(n) {
  
    /* Cifra koja je bila tekuca u prethodnoj iteraciji petlje,
     * u novoj iteraciji postaje prethodna.
     * 
     * Novoizdvojena cifra je tekuca.
     */
    prethodna_cifra = tekuca_cifra;
    tekuca_cifra = n % 10;
    
    /* Ukoliko smo naisli na cifre koje kvare rastuci poredak,
     * prekidamo izvrsavanje funkcije sa odgovarajucom povratnom vrednoscu 0.
     */
     if(prethodna_cifra < tekuca_cifra)
	return 0;
    
    /* Inace, nastavljamo sa izdvajanjem cifara */
    n /= 10;
  }
  
  return 1;
}

int main() {

  int x;
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  if(rastuce(x))
    printf("Cifre su u rastucem poretku!\n");
  else
    printf("Cifre nisu u rastucem poretku!\n");
  
  return 0;
}