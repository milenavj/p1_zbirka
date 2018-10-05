#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b, c;
  float as;

  /* Ucitavaju se tri cela broja. */
  printf("Unesite tri cela broja:");
  scanf("%d%d%d", &a, &b, &c);

  /* Pogresan nacin: as = (a+b+c)/3;
     Kada se operacija / koristi nad celim brojevima,
     deljenje je celobrojno.
     Na primer, (1+1+3)/3 ima vrednost 1.*/
  
  /* Ispravan nacin je da se bar jedan operand 
     pretvori u realan broj. */
  as = (a + b + c) / 3.0;

  /* Drugi ispravni nacini:
     as=1.0*(a+b+c)/3;
     as=(0.0+a+b+c)/3;
     as=((float)(a+b+c))/3; */

  /* Ispis rezultata. */
  printf("Aritmeticka sredina:  %.2f\n", as);
  
  return 0;
}
