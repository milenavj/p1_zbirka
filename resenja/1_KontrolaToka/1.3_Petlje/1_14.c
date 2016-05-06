/*
Napisati program koji ispisuje sve prave delioce unetog pozitivnog celog broja.

*/

#include<stdio.h>
#include<math.h>
int main()
{
   int x;
   int i;
      
    printf("Unesi x>0:");  
    scanf("%d", &x);

    if (x<=0)                        
    {
        printf("Neispravan unos\n"); 
	return -1;                   
    }                                
   
   /* 1. nacin */
   printf("------------ 1. nacin ------------\n");
   for(i=2;i<x;i++)
   {
      printf("proveravam za %d...\n",i);
      if (x%i==0)
         printf("\t delilac:%d \n",i);
   }
   /* 2. nacin (brzi) */
   printf("------------ 2. nacin ------------\n");
   for(i=2;i<=sqrt(x);i++)
   {
      printf("proveravam za %d...\n",i);
      if (x%i==0)
        if (i==x/i)  /* u slucaju kada je delilac koren broja, npr 4 za 16, ispisujemo ga jednom */
         printf("\t delilac:%d \n",i);
        else         /* u suprotnom, npr 2 za 16, ispisujemo i 2 i 8 */        
         printf("\t delioci:%d %d \n",i,x/i);
   }
   return 0;
}