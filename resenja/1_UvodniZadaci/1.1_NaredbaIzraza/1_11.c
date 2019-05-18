#include <stdio.h>

int main() {
  /* Deklaracija potrebne promenljive. */
  unsigned int cena;
  
  /* Ucitavanje cene proizvoda. */
  printf("Unesite cenu proizvoda: ");
  scanf("%u", &cena);

  /* Vrednost cena/5000 predstavlja maksimalan broj novcanica od 5000
     dinara koje je moguce iskoristiti za placanje racuna.
     Na primer, neka je uneta cena 8367 dinara, vrednost izraza 
     8367/5000 je jednaka 1. */
  printf("%u = %u*5000 + ", cena, cena / 5000);
  
  /* Da bi se isti postupak primenio i na ostale novcanice, potrebno
     je izracunati preostali iznos. Jedan nacin da se to uradi je
     racunanje ostatka pri deljenju unete vrednosti cena 
     (u primeru 8367) sa 5000. On iznosi 3367. Ova vrednost se 
     dodeljuje promeljivoj cena. */
  cena = cena % 5000;

  /* Ponavljanje postupka za ostale novcanice. */
  printf("%u*2000 + ", cena / 2000);
  cena = cena % 2000;
  printf("%u*1000 + ", cena / 1000);
  cena = cena % 1000;
  printf("%u*500 + ", cena / 500);
  cena = cena % 500;
  printf("%u*200 + ", cena / 200);
  cena = cena % 200;
  printf("%u*100 + ", cena / 100);
  cena = cena % 100;
  printf("%u*50 + ", cena / 50);
  cena = cena % 50;
  printf("%u*20 + ", cena / 20);
  cena = cena % 20;
  printf("%u*10 + ", cena / 10);
  cena = cena % 10;
  printf("%u*1\n", cena);

  return 0;
}
