#include <stdio.h>
/*
Napisati program koji za uneti ceo broj x ispisuje da li je jednak nuli,
manji od nule ili veci od nule.
*/
int main()
{
  int x;
  printf("Unesi ceo broj:");
  scanf("%d",&x);
  
  /*
     obratiti paznju:
     x==0 - relacija jednakosti (da li je vrednost promenljive x jednaka nuli)
     x=0 - naredba dodele (promenljiva x dobija vrednost nula)
  */
  if (x==0)
    printf("Broj je jednak nuli\n");
  else if (x<0)
    printf("Broj je manji od nule\n");
  else
    printf("Broj je veci od nule\n");
    
  return 0;
}