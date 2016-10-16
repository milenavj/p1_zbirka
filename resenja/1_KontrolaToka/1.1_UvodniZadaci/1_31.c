#include <stdio.h>

int main()
{
   float a,b,rez;
   float min,max;
   printf("Unesite dva realna broja:");
   scanf("%f%f",&a,&b);
   
   /* 
      Odredjujemo minimalnu i maksimalnu vrednost 
      unetih brojeva
   */
   min = (a<b) ? a : b;
   max = (a>b) ? a : b;
   
   /*
      Racunamo vrednost promenljive rez
   */
   rez = (min+0.5)/(1+max*max);
   
   printf("Rezultat je %.2f\n", rez);
   
   return 0;
}