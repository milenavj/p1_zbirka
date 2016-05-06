/*
Napisati program koji ucitava trocifreni broj koji se 
unosi sa standardnog ulaza i ispisuje njegove cifre na 
standardni izlaz.
*/
#include <stdio.h>
int main()
{
   int x;
   int cifra_jedinice;
   int cifra_desetice;
   int cifra_stotine;
   
   printf("Unesi trocifreni broj:");
   scanf("%d", &x);
   
   cifra_jedinice = x%10;
   cifra_desetice = (x/10)%10;
   cifra_stotine = x/100;
   
   printf("Cifre unetog broja su %d,%d,%d\n", cifra_jedinice, cifra_desetice, cifra_stotine);
   
   /*
     2. nacin, bez uvodjenja dodatnih promenljivih cifra_jedinice,cifra_desetice i cifra_stotine:
	 
	 printf("Cifre unetog broja su %d,%d,%d\n", x%10, (x/10)%10, x/100);
   */
   return 0;
}