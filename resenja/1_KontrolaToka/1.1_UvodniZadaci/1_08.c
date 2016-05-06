/*
   Napisati program koji za unetu cenu proizvoda ispisuje najmanji broj
   novcanica koje je potrebno izdvojiti da bi se proizvod platio. Na
   raspolaganju su novcanice od 1000,100,50,10 i 1 dinar. Na primer,
   za unetu cenu 5178, program na standardni izlaz treba da ispise:
   5178=5*1000+ 1*100 +1*50 +2*10 +8*1   
*/

#include <stdio.h>

int main()
{
   int x;
   printf("Unesi cenu:");
   scanf("%d", &x);
   
   printf("%d=%d*1000+ ", x,x/1000);
   x=x%1000;
   printf("%d*100 +", x/100);
   x=x%100;
   printf("%d*50 +",x/50);
   x=x%50;
   printf("%d*10 +", x/10);
   x=x%10;
   printf("%d*1\n", x);
   return 0;
}