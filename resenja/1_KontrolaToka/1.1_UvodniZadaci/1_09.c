/*
Napisati program koji za tri cela broja koja se unose sa standardnog ulaza
ispisuje njihovu aritmeticku sredinu na standardni izlaz.
*/

#include<stdio.h>

int main()
{
  int a, b, c;
  float as;
  
  printf("Unesi tri cela broja:");
  scanf("%d%d%d",&a,&b,&c);
  
  as=(a+b+c)/3.0; /* da bismo dobili kolicnik, jedan argument mora da bude realan broj */
  
  /*
  moguce je i:
  as=1.0*(a+b+c)/3;
  ili
  as=((float)(a+b+c))/3;
  */
  
  printf("Aritmeticka sredina unetih brojeva je %f\n", as);
  return 0;
}