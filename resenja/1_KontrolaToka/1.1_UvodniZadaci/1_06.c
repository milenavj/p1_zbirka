
#include <stdio.h>
int main()
{
   int x;
   int obrnuto_x;
   
   int cifra_jedinice;
   int cifra_desetice;
   int cifra_stotine;
   
   printf("Unesi trocifreni broj:");
   scanf("%d", &x);
   
   cifra_jedinice = x%10;
   cifra_desetice = (x/10)%10;
   cifra_stotine = x/100;
   
   obrnuto_x = cifra_jedinice*100 + 
               cifra_desetice*10 + 
               cifra_stotine;
   
   printf("Obrnuto: %d\n", obrnuto_x);
   
   return 0;
}