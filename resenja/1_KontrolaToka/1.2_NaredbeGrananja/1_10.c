
#include<stdio.h>

int main()
{
   float x;
   float y;

   printf("Unesite jedan realan broj:");
   scanf("%f",&x);

   y=x;
   if (y<0)
     y=-y;

   printf("Njegova apsolutna vrednost je %.2f\n",y);
   
   
   /* 
      2. nacin, pomocu funkcije fabs se nalazi u zaglavlju math.h: 
      y=fabs(x);
   */
   return 0;
}