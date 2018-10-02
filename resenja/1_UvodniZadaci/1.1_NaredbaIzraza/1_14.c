#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int broj, novibroj;
  unsigned int levo, desno;
  
  /* Ucitava se neoznacen ceo broj. */
  printf("Unesite broj: ");
  scanf("%u", &broj);

  /* Desni deo rezultata je cifra jedinice unetog broja. 
     Na primer, za broj 1234, desni deo je cifra 4. */
  desno = broj%10;
  
  /* Levi deo rezultata su sve cifre levo od cifre desetice. 
     Na primer, za broj 1234, levi deo je broj 12 i dobija se
     deljenjem unetog broja sa 100. */
  levo = broj/100;
  
  /* Rezultat se dobija spajanjem levog i desnog dela.
     U datom primeru: 12*10 + 4 = 124. */
  novibroj = levo*10 + desno;
  
  /* Ispis rezultata. */
  printf("Rezultat je: %u\n", novibroj);

  return 0;
}
