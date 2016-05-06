/*
  Napisati funkciju koja za dva data cela broja odredjuje
  najveci zajednicki delilac. Napisati potom glavni program
  koji testira ovu funkciju.
*/

#include <stdio.h>

int euklid(int x, int y)
{
  int r;
  /* Euklidov algoritam */
  while(y)   /* algoritam se zaustavlja kada vrednost */
  {          /* promenljive y postane nula */
    r=x%y;
    x=y;
    y=r;
  }
  
  return x; /* nzd je sacuvan u promenljivoj x */
}

int main()
{
  int a,b;
  int nzd;
  
  printf("unesi dva cela broja:");
  scanf("%d%d", &a,&b);
  
  nzd = euklid(a,b);  /* promenljivoj nzd dodeljujemo povratnu vrednost funkcije euklid */
  
  printf("najveci zajednicki delilac za %d i %d je %d\n", a,b,nzd);
  
  return 0;
}