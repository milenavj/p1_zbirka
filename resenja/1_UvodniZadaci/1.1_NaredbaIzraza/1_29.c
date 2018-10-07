#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b;
  int rezultata, rezultatb, rezultatc;

  /* Ucitavaju se dva cela broja. */
  printf("Unesite dva cela broja: ");
  scanf("%d%d", &a, &b);

  /* Izraz a != b ima vrednost 1 ako je ova relacija tacna, a 0 ako
     je netacna. */
  rezultata = a != b;

  /* Izraz a%2==0 && b%2==0 je konjunkcija koja se sastoji od dve
     relacije poredjenja jednakosti. Izraz a%2==0 ima vrednost 1 ako
     je ova relacija tacna, a 0 u suprotnom. */
  rezultatb = (a % 2 == 0 && b % 2 == 0);

  /* Izraz a>0 && a<=100 && b>0 && b<=100 je konjunkcija koja se
     sastoji od cetiri konjunkata. Svaki od konjunkata je izraz
     koji sadrzi relacioni operator i ima vrednost 1 ako relacija
     vazi, a 0 ako ne vazi. */
  rezultatc = (a > 0 && a <= 100 && b > 0 && b <= 100);

  /* Ispis rezultata. */
  printf("a) rezultat=%d\n", rezultata);
  printf("b) rezultat=%d\n", rezultatb);
  printf("c) rezultat=%d\n", rezultatc);

  return 0;
}
