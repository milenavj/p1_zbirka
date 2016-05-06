/*
Napisati program koji za koeficijente kvadratne jednacine
koji se unose sa standardnog ulaza na standardni izlaz
ispisuje koliko realnih resenja jednacina ima i ako ih ima, ispisuje resenja jednacine
zaokruzena na dve decimale.
*/
#include <stdio.h>
#include <math.h>
int main()
{
   float a,b,c;
   float D;
   float x1,x2;
   printf("Unesi koeficijente kvadratne jednacine:");
   scanf("%f%f%f",&a,&b,&c);
   
   /* proveravamo da li je kvadratna jednacina korektno zadata */
   if (a==0)
      if (b==0) 
         if(c==0) /* slucaj a==0 && b==0 && c==0 */
              printf("Jednacina ima beskonacno mnogo resenja\n");
         else /* slucaj a==0 && b==0 && c!=0 */
              printf("Jednacina nema resenja\n");
      else /* slucaj a==0 && b!=0 */
      {
         x1=-c/b;
         printf("Jednacina ima jedinstveno realno resenje %.2f\n",x1);
      }
   else /* slucaj a!=0 */
   {

      D=b*b-4*a*c; /* funkcija sqrt nalazi se u biblioteci math.h (prevodjenje sa -lm opcijom) */
      if (D<0)
        printf("Jednacina nema realnih resenja\n");
      else if (D>0)
      {
        x1 = (-b+sqrt(D))/(2*a);
        x2 = (-b-sqrt(D))/(2*a);
        printf("Jednacina ima dva razlicita realna resenja %.2f i %.2f\n",x1,x2);
      }
      else
      {
        x1 = (-b)/(2*a);
        printf("Jednacina ima jedinstveno realno resenje %.2f\n",x1);
      }  	
   }

   return 0;   
}