/*
   Napisati program koji poziva korisnika da unese pozitivan ceo broj n,
   a zatim za unetih n celih brojeva ispisuje sumu pozitivnih i sumu
   negativnih brojeva.

*/

#include<stdio.h>

int main()
{
   int n;
   int x;
   int suma_poz;
   int suma_neg;
   int i;
      
   printf("Unesi pozitivan ceo broj:");
   scanf("%d",&n);

   suma_poz=0;  /* promenljivim koje ce sadrzati sumu se pre ulaska u petlju */
   suma_neg=0;  /* dodeljuje  se 0 (neutral za sabiranje) */
   i=0;
   
   while(i<n)
   {
       printf("Unesi ceo broj:");
       scanf("%d", &x);
       
       if (x<0)
          suma_neg+=x;
       else
          suma_poz+=x;
          
       i++;
   }
   
   printf(" Suma pozitivnih: %d\n Suma negativnih: %d\n",suma_poz,suma_neg);
   return 0;
}