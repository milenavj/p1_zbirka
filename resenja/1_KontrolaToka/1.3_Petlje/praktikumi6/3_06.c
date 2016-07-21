#include <stdio.h>

int main() {
  
  unsigned int x;
  int pozicija;     // da li se radi o cifri jedinici, desetici, stotini itd...
  int cifra;        // trenutna izdvojena cifra iz broja x
  unsigned int y;   // broj dobijen nakon transformacije
  
  printf("Unesite broj: ");
  scanf("%d", &x);
  
  
  if(x > 0) {
    
    /* Posto pocinjemo sa izdvajanjem cifara od cifre jedinica, 
      postavljamo tezinu (stepen) pozicije na 1 */
    pozicija = 1;
    y = 0;
    
    /* Sve dok imamo cifara u zapisu broja */
    while(x > 0) {
    
      /* Izdvajamo poslednju cifru iz zapisa */
      cifra = x % 10; 
      
      /* Proveravamo da li je cifra parna */
      if(cifra % 2 == 0){
        /* I ako jeste, uvecavamo je */
        cifra++;
        
      }
      
      /* Novi broj formiramo tako sto izdvojenu cifru pomnozimo odgovarajucom
          tezinom (stepenom) pozicije */
      y += cifra*pozicija; 
      
      /* Pripremamo broj za izdvajanje naredne cifre */
      x /= 10;
      
      /* I uvecavamo tezinu (stepen) pozicije */
      pozicija *= 10;
    }

    /* Ispisujemo izracunatu vrednost */
    printf("%d\n", y);
  }
  else	
    printf("Nekorektan unos.\n");

  return 0;
}