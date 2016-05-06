/*
   Napisati program koji poziva korisnika da unese dve celobrojne vrednosti,
   smesta ih u promenljive x i y, zamenjuje vrednosti tih promenljivih i 
   stampa ih na standardni izlaz.
*/
#include<stdio.h>
int main()
{
   int x,y;
   int t;
   printf("Unesi dve celobrojne vrednosti:");
   scanf("%d%d",&x,&y);
   printf("x=%d, y=%d\n",x,y);
   t=x;  /* promenljiva t dobija vrednost promenljive x */
   x=y;  /* promenljiva x dobija vrednost promenljive y */
   y=t;  /* promenljiva y dobija vrednost promenljive t */
   printf("nakon zamene, x=%d, y=%d\n",x,y);
   return 0;
}