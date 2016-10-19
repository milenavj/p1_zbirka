#include <stdio.h>

int main()
{
   int x;
   printf("Unesite godinu:");
   scanf("%d",&x);
   
   if ((x%4==0 && x%100!=0) || x%400==0)
      printf("Godina je prestupna\n");
   else
      printf("Godina nije prestupna\n");
      
   return 0;
}
