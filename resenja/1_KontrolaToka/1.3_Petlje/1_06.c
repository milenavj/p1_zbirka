#include<stdio.h>
#include<stdlib.h>

int main()
{
   int x;
   char cifra;
   printf("Unesi ceo broj:");
   scanf("%d", &x);
   
   /* Pretvaranje u apsolutnu vrednost se vrsi za slucaj kada je unet 
    * negativan broj kako bismo osigurali da ce nam izdvojene cifre 
    * biti pozitivne.
    */
   x = abs(x); 
   
   /* Kako uklanjamo cifre broja (pogledati telo petlje)
    * u nekom trenutku broj ce postati 0 jer smo uklonili
    * sve njegove cifre. Tada prekidamo rad petlje.
    */
   while(x>0)
   {
	  /* Izdvajamo poslednju cifru broja x. */
      cifra=x%10;            
      printf("%d\n", cifra);
      /* Uklanjamo poslednju cifru broja x. */
      x/=10;                
   }
   
   return 0;
}
