/*
  Napisati program koji za 2 cela broja uneta sa standardnog ulaza 
  ispisuje njihov minimum na standardni izlaz. 
*/

#include <stdio.h>
int main()
{
   int a,b;
   int min1;
   int min2;
   int min3;
   
   scanf("%d%d",&a,&b);
   
   
   /* 1. nacin */   
   if (a<b)
      min1=a;
   else
      min1=b;
	  
   printf("Minimum unetih brojeva (1.nacin) je %d\n",min1);	  
   
   /* 2. nacin */   
   min2 = (a<b) ? a : b;
   printf("Minimum unetih brojeva (2.nacin) je %d\n",min2);	  
   
   /* 3. nacin */
   min3=a;
   if (b<a)      
      min3 = b;
   printf("Minimum unetih brojeva (3.nacin) je %d\n",min3);   
         
   return 0;
}