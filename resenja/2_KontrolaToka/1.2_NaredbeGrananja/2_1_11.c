#include <stdio.h>
#include <ctype.h>

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int c1, c2, c3;

  /* Ucitavanje sifre artikla. */
  printf("Unesite sifru: ");
  c1 = getchar();
  c2 = getchar();
  c3 = getchar();

  /* Funkcije islower, isupper i isdigit proveravaju da li je
     prosledjeni karakter malo slovo, veliko slovo ili cifra.
     Deklaracije ovih funkcija se nalaze u zaglavlju ctype.h.

     Ukoliko prvi karakter nije ni malo slovo ni veliko slovo, ni
     cifra, ispisuje se odgovarajuca poruka o gresci i izlazi se
     iz programa. */
  if (!islower(c1) && !isupper(c1) && !isdigit(c1)) {
    printf("Greska: %c je neispravan karakter.\n", c1);
    return 1;
  }

  /* Postupak se ponavlja za druga dva karaktera. */
  if (!islower(c2) && !isupper(c2) && !isdigit(c2)) {
    printf("Greska: %c je neispravan karakter.\n", c2);
    return 1;
  }

  if (!islower(c3) && !isupper(c3) && !isdigit(c3)) {
    printf("Greska: %c je neispravan karakter.\n", c3);
    return 1;
  }

  /* Funkcija tolower(c) radi sledece: ako je c veliko slovo, kao
     povratnu vrednost vraca odgovarajuce malo slovo, u suprotnom
     vraca c. Dakle, tolower('A') je 'a', a tolower('6') = '6',...

     Slicno, samo obrnuto, radi i funkcija toupper(c). Deklaracije 
     ovih funkcija se takodje nalaze u zaglavlju ctype.h. */
  c1 = tolower(c1);
  c2 = tolower(c2);
  c3 = tolower(c3);

  printf("%c%c%c\n", c1, c2, c3);

  return 0;
}
