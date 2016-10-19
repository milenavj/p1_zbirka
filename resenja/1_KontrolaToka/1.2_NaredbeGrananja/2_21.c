
#include <stdio.h>
#include <math.h>
int main()
{
   float a,b,c;
   float D;
   float x1,x2;
   printf("Unesite koeficijente A, B i C:");
   scanf("%f%f%f",&a,&b,&c);
   
   /* 
        Proveravamo da li je kvadratna jednacina 
        korektno zadata. 
   */
   if (a==0)
      if (b==0) 
         /* slucaj a==0 && b==0 && c==0 */
         if(c==0) 
              printf("Jednacina ima beskonacno mnogo resenja\n");
         /* slucaj a==0 && b==0 && c!=0 */     
         else 
              printf("Jednacina nema resenja\n");
      /* slucaj a==0 && b!=0 */        
      else 
      {
         x1=-c/b;
         printf("Jednacina ima jedinstveno realno resenje %.2f\n",
                                                              x1);
      }
   /* slucaj a!=0 */   
   else 
   {

      D=b*b-4*a*c; 
      if (D<0)
        printf("Jednacina nema realnih resenja\n");
      else if (D>0)
      {
        /* funkcija sqrt nalazi se u biblioteci math.h 
           (prevodjenje sa -lm opcijom) */
        x1 = (-b+sqrt(D))/(2*a);
        x2 = (-b-sqrt(D))/(2*a);
        printf("Jednacina ima dva razlicita realna resenja %.2f ",
                                                "i %.2f\n",x1,x2);
      }
      else
      {
        x1 = (-b)/(2*a);
        printf("Jednacina ima jedinstveno realno resenje %.2f\n",x1);
      }  	
   }

   return 0;   
}