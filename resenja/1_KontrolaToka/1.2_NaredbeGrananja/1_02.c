/*
Napisati program koji za uneti ceo broj ispisuje njegovu reciprocnu vrednost.
Ukoliko je uneti broj jednak nuli, ispisati poruku "Nedozvoljeno deljenje nulom".
*/

#include <stdio.h>

int main()
{
   int x;
   float rx;
   
   printf("Unesi jedan ceo broj:");
   scanf("%d",&x);
   
  /*
     obratiti paznju:
     x==0 - relacija jednakosti (da li je vrednost promenljive x jednaka nuli)
     x=0 - naredba dodele (promenljiva x dobija vrednost nula)
  */

   if (x==0)
      printf("Nedozvoljeno deljenje nulom\n");
   else
   {
      rx = 1.0/x;
      printf("Reciprocna vrednost unetog broja:%f\n",rx);
   }
   
   return 0;
}