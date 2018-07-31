#include <stdio.h>

/* U broju y (ukoliko postoji) izbacuje se cifra 'cifra'. Poredak cifara nije bitan, dobijena vrednost ima obrnut redosled  cifara. */
int izbaci_cifru(int y, int cifra) {
  /* Vrednost broja y nakon eliminisanja cifre. Poredak cifara nije bitan pa ce vrednost novo_y imati obrnut poredak u odnosu na broj y. Na pocetku se postavlja na 0 i generise se koriscenjem Heronovog obrasca. */
  int novo_y = 0;
  /* Indikator da li je cifra uklonjena iz broja y. */
  int indikator = 0;
  /* Pomocni parametar u kome se cuva trenutno izdvojena cifra u petlji. */
  int izdvojena_cifra;
  
  while(y) {
  
    izdvojena_cifra = y % 10;
    /* Tekuca cifra se ukljucuje prilikom formiranja novo_y u slucaju da se cifra razlikuje od one koja se eliminise ili ukoliko je jedna cifra vec elimisana. */
    if(izdvojena_cifra != cifra || indikator)
      
      /* Heronov obrazac. Menja poredak cifara, ali on u ovom slucaju i nije bitan. */
      novo_y = novo_y*10 + izdvojena_cifra;
    else 
      
      /* U slucaju da je cifra vec eliminisana, ne treba je opet eliminisati. Zato se menja vrednost indikatora. */
      indikator = 1;
    
    y /= 10;
  }
  
  return novo_y;
}

/* Funkcija proverava da li su dva cela broja napisana pomocu istih cifara, kao i da li se te cifre pojavljuju isti broj puta. */
int zapis(int x, int y) {
  
  /* Cifra koja se izdvaja iz x, a onda eliminise iz y. */
  int cifra;
  
  /* Radi lakseg rada, posmatraju se pozitivne vrednosti datih brojeva. */
  x = abs(x);
  y = abs(y);
  
  /* Iz broja x izdvajaju se redom cifra po cifra s kraja, a zatim se svaka takva cifra trazi i u broju y. Ukoliko postoji, eliminise se prvi put kada se pojavi (dakle, samo jednom). Ukoliko su sve cifre iste (***redosled nije bitan***), na kraju ce i iz x i iz y biti sve cifre eliminisane, te ostaju nule u oba broja. */
  while(x) {
  
    cifra = x % 10;
    x /= 10;
    
    y = izbaci_cifru(y, cifra);
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
