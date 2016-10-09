
#include <stdio.h>

int main()
{
   unsigned x;
   printf("Unesi cenu:");
   scanf("%u", &x);
   
   /* 
      Na primer, neka je uneta cena 8347 dinara. 
      Vrednost x/5000 predstavlja broj novcanica 
      od 5000 dinara pomocu kojih mozemo sakupiti
      celokupnu sumu. 8347 celobrojno deljeno sa 
      5000 (operacija / nad celim brojevima) iznosi 1.  
   */
   printf("%u=%u*5000+ ", x,x/5000); 
   /*
      Potrebna nam je 1 novcanica od
      5000 dinara, a koliko nam je potrebno ostalih
      novcanica? Za to moramo pristupiti preostaloj 
      sumi. Jedan nacin je da nadjemo ostatak pri deljenju
      unete vrednosti x (u primeru 8347) sa 5000 (operacija %). 
      On iznosi 3347. Ovu vrednost dodeljujemo promeljivoj x.
   */
   x=x%5000;
   
   /*
      Nastavljamo postupak trazenjem broja novcanica 
      od 2000 dinara i redom za ostale monete.  
   */
   printf("%u*2000 +", x/2000);
   x=x%2000;
   printf("%u*1000 +", x/1000);
   x=x%1000;
   printf("%u*500 +", x/500);
   x=x%500;
   printf("%u*200 +", x/200);
   x=x%200;
   printf("%u*100 +", x/100);
   x=x%100;
   printf("%u*50 +",x/50);
   x=x%50;
   printf("%u*20 +", x/20);
   x=x%20;
   printf("%u*10 +", x/10);
   x=x%10;
   printf("%u*1\n", x);
   return 0;
}