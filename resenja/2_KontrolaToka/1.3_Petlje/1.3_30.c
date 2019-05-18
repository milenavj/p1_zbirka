#include <stdio.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int x, x_kopija, x_obrnuto;

  /* Ucitavanje vrednosti pocetnog broja. */
  printf("Unesite broj: ");
  scanf("%d", &x);

  /* Racunanje apsolutne vrednosti unetog broja.  */
  if (x < 0)
    x = -x;

  /* Racunanje broja koji se dobije kada se broju x obrnu cifre. Na
     primer, od 12345 treba da se dobije 54321. Broj se obrce tako
     sto se u svakoj iteraciji njegova vrednost pomnozi sa 10 i
     doda mu se sledeca cifra polaznog broja. 
     Za x_kopija=12345, x_obrnuto = 0 
     1. iteracija: x_obrnuto = 0*10 + 5 = 5, x_kopija = 1234 
     2. iteracija: x_obrnuto = 5*10 + 4 = 54, x_kopija = 123, 
     3. iteracija: x_obrnuto = 54*10 + 3 = 543, x_kopija = 12, 
     itd. */
  x_kopija = x;
  x_obrnuto = 0;
  while (x_kopija != 0) {
    x_obrnuto = x_obrnuto * 10 + x_kopija % 10;
    x_kopija /= 10;
  }

  /* Broj je palindrom ako je jednak broju koji se dobije
     obrtanjem njegovih cifara. Npr. x = 12321, x_obrnuto je
     takodje 12321. */
  if (x == x_obrnuto)
    printf("Broj je palindrom.\n");
  else
    printf("Broj nije palindrom.\n");

  return 0;
}
