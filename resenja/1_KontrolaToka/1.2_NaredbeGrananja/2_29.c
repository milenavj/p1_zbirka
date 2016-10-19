#include <stdio.h>

int main()
{
  int d,m;
  printf("Unesite dan i mesec");
  scanf("%d%d",&d,&m);
  
  /* 
    Argument u naredbi switch mora biti celobrojna promenljiva,
    dok argument u naredbi case mora biti celobrojna 
    konstanta.   
  */
  switch(m) 
  {
     /* Ispitujemo da li vazi m==1 ili m==2*/
     case 1: 
     case 2: 
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
          printf("prolece\n");
        else
          printf("leto\n");
        break;
     case 7:
     case 8:
        printf("leto\n");
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
