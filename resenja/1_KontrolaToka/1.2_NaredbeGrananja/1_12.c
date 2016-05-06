/*
Napisati program koji za uneti dan i mesec ispisuje godisnje doba kom
pripadaju. Mozemo podrazumevati da je unos korektan. 
*/

#include <stdio.h>

int main()
{
  int d,m;
  printf("Unesi dan i mesec");
  scanf("%d%d",&d,&m);
  
  switch(m) /* argument u naredbi switch mora biti celobrojna promenljiva */
  {
     case 1: /* argument u naredbi case mora biti celobrojna konstanta */
     case 2: /* ispitujemo da li je m==2 */
        printf("zima\n");
        break;
     case 3:
        if (d<21)
          printf("zima\n");
        else
          printf("prolece\n");
        break;
     case 4:
     case 5:
        printf("prolece\n");
        break;
     case 6:
        if (d<21)
          printf("prolece");
        else
          printf("leto");
        break;
     case 7:
     case 8:
        printf("leto");
        break;
     case 9:
        if (d<23)
          printf("leto\n");
        else
          printf("jesen\n");
        break;
     case 10:
     case 11:
        printf("jesen\n");
        break;
     case 12:
        if (d<22)
          printf("jesen\n");
        else
          printf("zima\n");
  }
  return 0;
}