/*
   Napisati program koji za uneti pozitivan ceo broj
   izracunava njegov faktorijel. Testirati program
   za razlicite vrednosti promenljive x. Obratiti paznju
   da pocev od 23! dolazi do prekoracenja.
*/

#include<stdio.h>

int main()
{
  int x;
  unsigned long f;
  int i;
  int original;
  
  printf("Unesi x>=0:");
  scanf("%d",&x);
  
  original=x;
  f=1;
  if (x<0)
    printf("Nekorektan unos\n");     
  else
  {
     while (x>1)
     {
        f=f*x; /* vrednost izraza sa desne strane naredbe dodele 
                  dodeljujemo promenljivoj sa leve strane naredbe dodele
               */
        x--;  /* operator -- umanjuje vrednost promenljive x za 1
                 naredba x--; ima isti efekat kao x-=1;
                 ili x=x-1;        
              */
     }
     printf("%d! = %lu\n",x,f);        /* nekorektno: vrednost promenljive x je unistena */
     printf("%d! = %lu\n",original,f); /* korektno: promenljiva original sadrzi vrednost promenljive x pre ulaska u petlju */

  }
  

  return 0;
}