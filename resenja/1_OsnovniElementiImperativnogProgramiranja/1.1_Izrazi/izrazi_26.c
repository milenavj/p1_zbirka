#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a, b, c;
  float aritmeticka_sredina;

  /* Ucitavanje vrednosti tri cela broja. */
  printf("Unesite tri cela broja:");
  scanf("%d%d%d", &a, &b, &c);

  /* Pogresan nacin: aritmeticka_sredina = (a+b+c)/3;
     Kada se operacija / koristi nad celim brojevima,
     deljenje je celobrojno.
     Na primer, (1+1+3)/3 ima vrednost 1.*/
  
  /* Ispravan nacin je da se bar jedan operand 
     pretvori u realan broj. */
  aritmeticka_sredina = (a + b + c) / 3.0;

  /* Drugi ispravni nacini:
     aritmeticka_sredina=1.0*(a+b+c)/3;
     aritmeticka_sredina=(0.0+a+b+c)/3;
     aritmeticka_sredina=((float)(a+b+c))/3; */

  /* Ispis rezultata. */
  printf("Aritmeticka sredina:  %.2f\n", aritmeticka_sredina);
  
  return 0;
}
