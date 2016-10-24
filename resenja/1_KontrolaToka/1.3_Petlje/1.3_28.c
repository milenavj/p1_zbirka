#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
  
  int x;
  /* Tezina trenutne pozicije u broju. Moze biti 1, 10, 100, 
   * 1000 itd. 
   */
  int stepen_deset; 
  /* Trenutna izdvojena cifra iz broja x. */
  int cifra;       
  /* Redni broj cifre koja se trenutno obradjuje, gledano s desna 
   * na  levo. 
   */ 
  int rbr; 
  /* Broj dobijen nakon transformacije. */
  int y;  
  /* Promenljiva znak cuva znak unesenog broja. Moze biti
   * -1 za negativnu vrednost ili 1 za poziivnu vrednost.
  */
  int znak = 1;
  
  /* Ucitavanje broja. */
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  if(x <= 0) 
  {
	  x = abs(x);
	  znak = -1;
  }
    /* Postavlja se vrednost stepena na 0 - to znaci da se prvo mnozi sa
     * 10^0=1.
     */
    stepen_deset = 0;
    
    /* Postavlja se vrednost broja koji se formira na 0. */
    y = 0;
    /* Postavlja se redni broj pozicije na 0. */
    rbr = 0;
  
    /* Provera da li ima cifara u zapisu broja. */
    while(x > 0) {
    
      /* Izdvajanje cifre. */
      cifra = x%10;
      
      /* Proverava se da li je pozicija izdvojene cifre parna - 
       * cifre na parnim pozicijama se zadrzavaju.
       */
      if(rbr % 2 == 0) {
        /* Ako jeste parna
         * izdvojena cifra se dodaje novom broju.
         * Neophodno je izvrsiti promenu tipova, jer je double povratni 
         * tip funkcije pow.
         */
        y += cifra * ((int) pow(10, stepen_deset)); 
        
        /* Uvecava se stepen zbog naredne cifre. */
        stepen_deset++;
      }
      
      /* Azurira se redni broj cifre. */
      rbr++;
      /* I priprema se broj za naredno izdvajanje. */
      x /= 10;
    }
  
    y = znak*y;
  
    /* Ispisuje se rezultat. */
    printf("%d\n", y);


  return 0;
}
