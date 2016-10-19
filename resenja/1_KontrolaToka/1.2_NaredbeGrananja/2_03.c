
#include<stdio.h>

int main()
{
   float x;
   float apsolutno_x;

   printf("Unesite jedan realan broj:");
   scanf("%f",&x);

   apsolutno_x=x;
   if (x<0)
     apsolutno_x=-x;

   printf("Njegova apsolutna vrednost je %.2f\n",apsolutno_x);
   
   
   /* 
      2. nacin, pomocu funkcije fabs za koju je neophodno 
      ukljuciti zaglavlje math.h: 
      apsolutno_x=fabs(x);
   */
   return 0;
}
