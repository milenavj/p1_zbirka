/* Sa standardnog ulaza unosi se neoznacen ceo broj. Napisati program koji
formira i ispisuje broj koji se dobija izbacivanjem svake druge cifre polaznog
broja. Cifre se posmatraju sa desna na levo.
*/

#include <stdio.h>
#include <math.h>

int main() {
  
  unsigned int x;
  int stepen_deset; // da li se radi o cifri jedinici, desetici, stotini itd...
  int cifra;        // trenutna izdvojena cifra iz broja x
  int rbr; // redni broj cifre koju trenutno obradjujemo, gledano s desna na  levo
  unsigned int y;   // broj dobijen nakon transformacije
  
  /* Ucitavamo broj */
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  if(x > 0) {
    /* Postavljamo vrednost stepena na 0 - to znaci da cemo prvo mnoziti sa
     * 10^0=1 */
    stepen_deset = 0;
    
    /* Postavljamo vrednost broja koji se formira na 0 */
    y = 0;
    /* Postavljamo redni broj pozicije na 0 */
    rbr = 0;
  
    /* Sve dok imamo cifara u zapisu broja */
    while(x > 0) {
    
      /* Izdvajamo cifru */
      cifra = x%10;
      
      /* Proveravamo da li je pozicija izdvojene cifre parna - 
       * cifre na parnim pozicijama zadrzavamo 
       */
      if(rbr % 2 == 0) {
        /* I ako jeste */
        
        /* Dodajemo izdvojenu cifru novom broju */
        /* Neophodno je izvrsiti "kastovanje" tipova, jer je double povratni tip
         * funkcije pow */
        y += cifra * ((int) pow(10, stepen_deset)); 
        
        /* Uvecavamo stepen zbog naredne cifre */
        stepen_deset++;
      }
      
      /* Azuriramo redni broj cifre */
      rbr++;
      /* I pripremamo broj za naredno izdvajanje */
      x /= 10;
    }
  
    /* Ispisujemo rezultat */
    printf("%d\n", y);
  }
  else
    printf("Nekorektan unos.\n");

  return 0;
}