/*

Napisati program koji za realan broj unet sa standardnog ulaza
ispisuje njegovu apsolutnu vrednost.

*/

#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
   float x;
   float y;

   printf("Unesi jedan realan broj:");
   scanf("%f",&x);

   /* 1. nacin */   
   if (x>0)
     y=x;
   else
     y=-x;
   printf("Apsolutna vrednost broja %f je %f\n",x,y);
   
   /* 2. nacin */
   y=x;
   if (y<0)
     y=-y;

   printf("Apsolutna vrednost broja %f je %f\n",x,y);
   
   /* 3. nacin - pogresan!*/
   y=abs(x); /* funkcija abs vraca ceo broj! za racunanje apsolutne vrednosti realnog broja treba koristiti funkciju fabs */
             /* funkcija abs se nalazi u zaglavlju stdlib.h */
   printf("Apsolutna vrednost broja %f je %f\n",x,y);
   
   /* 4. nacin */
   y=fabs(x); /* funkcija fabs se nalazi u zaglavlju math.h */
   printf("Apsolutna vrednost broja %f je %f\n",x,y);
   return 0;
}