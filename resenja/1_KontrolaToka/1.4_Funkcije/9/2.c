#include <stdio.h>

/* Funkcija int zapis(int x, int y) proverava da li su dva cela broja napisana
 * pomocu istih cifara, kao i da li se te cifre pojavljuju
 * isti broj puta.
 * Ideja je sledeca:
 * 	iz broja x izdvajaju se redom cifra po cifra s kraja,
 * 	a zatim se svaka takva cifra trazi i u broju y.
 * 	Ukoliko postoji, eliminise se prvi put kada se pojavi (dakle, samo jednom).
 * 	Ukoliko su sve cifre iste (***redosled nije bitan***),
 * 	na kraju ce i iz x i iz y biti sve cifre eliminisane",
 * 	te ostaju nule u oba broja.
 * 
 * 	Broj novo_y formira se, zbog jednostavnosti, pomocu Heronovog obrasca.	
 * 	Ovaj postupak obradjen je u okviru funkcije int izbaci_cifru(int y, int cifra).
 */

int izbaci_cifru(int y, int cifra) {

  int novo_y = 0;
  int indikator = 0;
  int izdvojena_cifra;
  
  while(y) {
  
    izdvojena_cifra = y % 10;
    /* U slucaju da se cifra razlikuje od one koju treba eliminisati,
     * ili ukoliko je jedna cifra vec elimisana =>
     * tekucu cifru ukljuciti prilikom formiranja novog y 
     * */
    if(izdvojena_cifra != cifra || indikator)
      
      /* Heronov obrazac. 
       * Menja poredak cifara, ali on u ovom slucaju i nije bitan.
       */
      novo_y = novo_y*10 + izdvojena_cifra;
    else 
      
      /* U slucaju da je cifra vec eliminisana,
       * ne treba je opet eliminisati.
       * Za svaku pojavu cifre iz x,
       * eliminise se jedna odgovarajuca pojava
       * te cifre iz y.
       */
      indikator = 1;
    
    y /= 10;
  }
  
  return novo_y;
}

int zapis(int x, int y) {
  
  /* Cifra koja se izdvaja iz x, a onda eliminise iz y */
  int cifra;
  
  /* U slucaju da su prosledjeni brojevi negativni */
  x = abs(x);
  y = abs(y);
  
  while(x) {
  
    cifra = x % 10;
    x /= 10;
    
    y = izbaci_cifru(y, cifra);
    
    /* otkomentarisati donju liniju radi lakseg pracenja rada programa: */
    // printf("Iz x izdvojeno: %d\n\tx = %d, y = %d\n\n", cifra, x, y);
  }
  
  return (x == 0 && y == 0);
}

int main() {

  int x, y;
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &x, &y);
  
  if(zapis(x, y))
    printf("Uslov je ispunjen!\n");
  else
    printf("Uslov nije ispunjen!\n");
  
  return 0;
}