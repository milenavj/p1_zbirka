/*
   Napisati program koji za uneti ceo broj ispisuje njegove cifre
   u obrnutom poretku.
*/

#include<stdio.h>
#include<stdlib.h>
int main()
{
   int x;
   char cifra;
   printf("Unesi ceo broj:");
   scanf("%d", &x);
   
   x = abs(x); /* pretvaranje u apsolutnu vrednost se vrsi za slucaj kada je unet 
                  negativan broj kako bismo osigurali da ce nam izdvojene cifre 
				  biti pozitivne
               */
   
   while(x>0)
   {
      cifra=x%10;            /* izdvajamo poslednju cifru broja x */
      printf("%d\n", cifra);
      x/=10;                /* ako je npr x=1582, x%10 ce biti 2,
                                                a x/10 ce biti 158;
                                      npr x=5, x%10 ce biti 5
                                             a x/10 ce biti 0 */
   }
   
   return 0;
}