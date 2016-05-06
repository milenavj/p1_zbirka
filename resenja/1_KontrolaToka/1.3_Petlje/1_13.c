/*
   a) Napisati program za uneti pozitivan ceo broj n ispisuje zbir
      s = 1+2^3+3^3+...+n^3. Na primer, za n=4, izlaz iz programa
      treba da bude:
      Suma kubova od 1 do 4 je 100
   b) Modifikovati program tako da ispisuje zbir s = 1+2^3+3^3+...+k^3 
      za svako i od 1 do n. Na primer, za n=4, izlaz iz programa treba da
bude:
i=1, n=1  
i=2, n=9
i=3, n=36
i=4, n=100

*/

#include <stdio.h>

int main()
{
 int n;
 int i;
 int s;
 
 
 printf("Unesite jedan pozitivan ceo broj:");
 scanf("%d", &n);

 if (n<0)
  return -1;

 i=1;
 s=0; /* inicijalizacija promenljive u kojoj se cuva suma kubova */
  
 for(i=1;i<=n;i++)
 {
     s+=i*i*i;
     /*  b) */
     printf("i=%d, s=%d\n", i, s);
 }   
 /* a) */
 printf("Suma kubova od 1 do %d: %d\n", n, s);
 return 0;
}
