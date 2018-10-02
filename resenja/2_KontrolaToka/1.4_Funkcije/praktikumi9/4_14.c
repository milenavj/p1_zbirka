#include <stdio.h>
#include <stdlib.h>

/* Funkcija proverava da li se cifre u zapisu broja nalaze u rastucem poretku. */
int rastuce(int n) {

  int tekuca_cifra;
  int prethodna_cifra;
  
  n = abs(n);
  
  /* Izvan petlje se izdvaja poslednja cifra u zapisu broja da bi u petlji mogla da se poredi sa sledecom. */
  tekuca_cifra = n % 10;
  n /= 10;
  
  while(n) {
  
    /* Izdvaja se nova cifra i ona postaje tekuca, a prethodna cifra se pamti. */
    prethodna_cifra = tekuca_cifra;
    tekuca_cifra = n % 10;
    
    /* Ukoliko dve uzastopne izdvojene cifre ne ispunjavaju rastuci poredak prekida se izvrsavanje funkcije sa odgovarajucom povratnom vrednoscu 0. */
     if(prethodna_cifra < tekuca_cifra)
		return 0;
    
    /* Inace, nastavlja se izdvajanje cifara. */
    n /= 10;
  }
 
  /* Nakon izlaska iz petlje povratna vrednost funkcije je 1 jer u slucaju da je poredak u nekom trenutku narusen iz funkcije bi se izaslo jos u petlji. */ 
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
