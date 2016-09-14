
#include <stdio.h>

int main()
{
   int x;
   printf("Unesi cenu:");
   scanf("%d", &x);
   
   /* 
      Na primer, neka je uneta cena 8347 dinara. 
      Vrednost x/1000 predstavlja broj novcanica 
      od 1000 dinara pomocu kojih mozemo sakupiti
      celokupnu sumu. 8347 celobrojno deljeno sa 
      1000 (operacija / nad celim brojevima) iznosi 8.  
   */
   printf("%d=%d*1000+ ", x,x/1000); 
   /*
      Potrebno nam je 8 novcanica od
      1000 dinara, a koliko nam je potrebno ostalih
      novcanica? Za to moramo pristupiti preostaloj 
      sumi. Jedan nacin je da nadjemo ostatak pri deljenju
      unete vrednosti x (u primeru 8347) sa 1000 (operacija %). 
      On iznosi 347. Ovu vrednost dodeljujemo promeljivoj x.
   */
   x=x%1000;
   /*
      Nastavljamo postupak trazenjem broja novcanica 
      od 100 dinara.  
   */
   printf("%d*100 +", x/100);
   x=x%100;
   printf("%d*50 +",x/50);
   x=x%50;
   printf("%d*10 +", x/10);
   x=x%10;
   printf("%d*1\n", x);
   return 0;
}