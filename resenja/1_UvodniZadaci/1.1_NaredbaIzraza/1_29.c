#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a, b;
  int rezultat_a, rezultat_b, rezultat_c;

  /* Ucitavanje dva cela broja. */
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &a, &b);

  /* Izraz a != b ima vrednost 1 ako je ova relacija tacna, a 0 ako
     je netacna. */
  rezultat_a = a != b;

  /* Izraz a % 2 == 0 && b % 2 == 0 je konjunkcija koja se sastoji
     od dve relacije poredjenja jednakosti. Izraz a % 2 == 0 ima
     vrednost 1 ako je ova relacija tacna, a 0 u suprotnom. */
  rezultat_b = (a % 2 == 0 && b % 2 == 0);

  /* Izraz a > 0 && a <= 100 && b > 0 && b <= 100 je konjunkcija
     koja se sastoji od cetiri konjunkta. Svaki od konjunkata je
     izraz koji sadrzi relacioni operator i ima vrednost 1 ako 
     relacija vazi, a 0 ako ne vazi. */
  rezultat_c = (a > 0 && a <= 100 && b > 0 && b <= 100);

  /* Ispis rezultata. */
  printf("a) rezultat=%d\n", rezultat_a);
  printf("b) rezultat=%d\n", rezultat_b);
  printf("c) rezultat=%d\n", rezultat_c);

  return 0;
}
