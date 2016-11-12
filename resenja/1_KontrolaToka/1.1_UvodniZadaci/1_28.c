#include <stdio.h>
#include <math.h>

int main()
{
  unsigned x, p;
  char c;
  unsigned levo, desno;
  unsigned novo_x;

  /* Ucitavamo potrebne vrednosti. Sa unosom podataka tipa char
     moramo biti pazljivi i o tome ce vise biti reci u narednim
     poglavljima kod zadataka za rad sa funkcijama getchar i
     putchar. Zbog toga cemo ovde za ucitavanje podataka zatraziti
     da podatke razdvajamo blanko znakovima (a ne znakom za novi
     red, zarezom ili nekim drugim separatorom). Ovaj zahtev
     navodimo u format stringu funkcije scanf tako sto
     specifikatore promenljivih razdvajamo blanko znakovima.

     Ukoliko specifikatore promenljivih u format stringu pisemo
     spojeno, tada ih prilikom unosa mozemo razdvojiti bilo kojim
     karakterom. Zbog toga blanko znakove u format stringu funkcije 
     scanf treba izbegavati i ovo je redak slucaj kada je njihova
     upotreba opravdana.

     Ako zelimo da odstampamo znak ", u format stringu funkcije
     printf navodimo \". */
  printf("Unesite vrednosti u formatu \"x p c\": ");
  scanf("%u %u %c", &x, &p, &c);

  /* Kada ucitavamo karaktersku promenljivu, njena numericka
     vrednost je jednaka ASCII kodu unetog karaktera. Na primer,
     ako karakter '0' ucitamo u promenljivu c, njena numericka
     vrednost bice 48. Da bismo pretvorili ovu numericku vrednost u 
     numericku vrednost koja odgovara cifri, od nje oduzimamo ASCII 
     kod karakterske konstante '0' koji iznosi upravo 48. */
  c = c - '0';

  /* Odredjujemo deo broja koji se nalazi desno od pozicije p */
  desno = x % (unsigned) pow(10, p);

  /* Odredjujemo deo broja koji se nalazi levo od pozicije p */
  levo = x / (unsigned) pow(10, p);

  /* Odredjujemo novi broj */
  novo_x =
      levo * (unsigned) pow(10, p + 1) + 
         c * (unsigned) pow(10, p) + desno;

  /* Ispisujemo dobijenu vrednost */
  printf("Rezultat je: %u\n", novo_x);

  /* Zavrsavamo sa programom */
  return 0;

}
