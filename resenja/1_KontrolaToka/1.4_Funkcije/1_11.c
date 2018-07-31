#include <stdio.h>

/* Funkcija za dva uneta neoznacena broja x i n utvrdjuje da li je x neki stepen
broja n. Ukoliko jeste, funkcija vraca izlozilac stepena, a u suprotnom vraca -1. */
int je_stepen(unsigned x, unsigned n) 
{
   int i=1;
   int s=n;
   
   /* Racuna se stepen broja n sve dok je on manji od x. */
   while(s<x)
   {
      s=s*n;
      i++;
   }
   
   /* Ukoliko je izracunati stepen jednak broju x onda funkcija vraca izlozilac stepena. */
   if (s==x)
      return i;
   
   /* U suprotnom vraca -1. */
   return -1;
}

int main()
{
  unsigned x;
  unsigned n;
  int st;
  
  scanf("%u%u",&x,&n);
  
  st = je_stepen(x,n);
  
  if (st!=-1)
    printf("%u=%u^%d\n",x,n,st);
  else
    printf("%u nije stepen broja %u\n",x,n);
  
  return 0;
}
