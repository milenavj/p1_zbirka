/*
Napisati C program koji ucitava sa standardnog ulaza cele brojeve dok ih je manje od 10 ili
dok ne naidje na nulu. Unetu nulu tretiramo kao validan unos. Program treba da ispise na standardni 
izlaz broj sa maksimalnom poslednjom cifrom.
Ako ima vise takvih brojeva neka ispise:
a) prvi unet broj sa maksimalnom poslednjom cifrom
b) poslednji unet broj sa maksimalnom poslednjom cifrom
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  int x;
  int x_sa_max_cifrom;
  char max_cifra;
  char cifra;

  max_cifra = -1;
  /*
  S obzirom da su cifre brojevi iz konacnog skupa {0,1,2,3,4,5,6,7,8,9},
  maksimalnu cifru inicijalizujemo na -1; u prvom prolazu kroz petlju,
  max_cifra ce promeniti vrednost (jer je svaka cifra >-1)   
  */
  
  for(n=0;n<10;n++)
  {
     printf("Unesi jedan ceo broj:");
     scanf("%d",&x);
      
     cifra=abs(x)%10;
     
     printf("%d\n",cifra);
     /* a) */
     /* if(cifra>max_cifra) */
     /* b) */
     if(cifra>=max_cifra)
     {
        x_sa_max_cifrom=x;
        max_cifra = cifra;
     }
     
     if (x==0)
        break;
  } 

  printf("Broj sa najvecom poslednjom cifrom: %d\n", x_sa_max_cifrom);
  return 0;
}
