/*
Napisati program koji poziva korisnika da unese pozitivan ceo broj n
a potom ispisuje brojeve od 0 do n-1.
*/

#include<stdio.h>

int main()
{
   int x;
   int n;
   
   printf("Unesi pozitivan ceo broj:");
   scanf("%d", &n);
   x=0;
   while (x<n)
   {
       printf("%d\n", x);
       x++; 
   }
   return 0;
}