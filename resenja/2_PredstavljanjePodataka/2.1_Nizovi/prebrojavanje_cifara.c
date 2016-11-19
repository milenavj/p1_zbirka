#include<stdio.h>
#include<stdlib.h>

int main()
{
   int x;
   int brojaci[10];  
   char cifra;
   int original;
   int i;
   
   /* Ucitava se ceo broj sa standardnog ulaza */
   printf("Unesite ceo broj:\n");
   scanf("%d",&x);
   
   /* Cuva se njegova originalna vrednost zbog finalnog ispisa */
   original = x;
   
   /* I nadalje posmatra apsolutna vrednost */
   x = abs(x);

   /* Svaki element niza brojaci predstavljace brojac za jednu od cifara:
      brojac[0] predstavljace broj nula u zapisu broja x
      brojac[1] predstavljace broj jedinica u zapisu broja x
      ...
      brojac[9] predstavljace broj devetki u zapisu broja x
   */  
   
   
   /* Brojaci se na pocetku inicijalizuju nulama */
   for(i=0;i<10;i++){
      brojaci[i]=0;
   }
  
   /* Sve dok ima cifara u zapisu broja x */
   do
   {
     /* Izdvaja se krajnja desna cifara */
     cifra = x%10;
     
     /* Uvecava se njen broj pojavljivanja */
      brojaci[cifra]++;  
      
      /* I prelazi se na analiziranje sledece cifre */
      x/=10;
      
   } while(x);
   
   /* Ispisuju se informacije o ciframa koje se nalaze u zapisu broja x */
   for(i=0; i<10; i++){
      if(brojaci[i]){
         printf("U zapisu broja %d, cifra %d se pojaviljuje %d puta\n", original, i, brojaci[i]);
      }
   }
   

  return 0;
}