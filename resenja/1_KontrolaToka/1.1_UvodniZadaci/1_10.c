#include<stdio.h>
int main()
{
   int x,y;
   int p;
   
   printf("Unesi dve celobrojne vrednosti:");
   scanf("%d%d",&x,&y);
   
   printf("pre zamene: x=%d, y=%d\n",x,y);

   /* Pomocna promenljiva p je potrebna da sacuva vrednost
      promenljive x pre nego sto se ona izmeni i dobije
      vrednost promenljive y. */
   p=x;  
   x=y;   
   y=p;
   printf("posle zamene: x=%d, y=%d\n",x,y);
   return 0;
}
