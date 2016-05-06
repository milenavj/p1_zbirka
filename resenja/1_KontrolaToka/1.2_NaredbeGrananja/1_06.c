/*
  a) Napisati program koji za 3 cela broja uneta sa standardnog ulaza 
  ispisuje njihov minimum na standardni izlaz.
  b) Neka uneti brojevi predstavljaju cene artikla. Ukoliko se najjeftiniji
  artikal dobija za 1 dinar, napisati kolika je ukupna cena, kao i koliko
  dinara se ustedi zahvaljujuci popustu.  
*/

#include <stdio.h>
int main()
{
   int a,b,c;
   int min;
   int min1;
   int min2;
   int cena_bez_popusta, cena_sa_popustom;
   
   scanf("%d%d%d",&a,&b,&c);
   
   
   if (a<b)
      if (a<c) /* poredak: a<b,a<c => a,b,c ili a,c,b */
         min=a;
      else     /* poredak: a<b, a>=c => a<b, c<=a => c,a,b */
         min=c;
   else        /* b<=a */
      if (b<c) /* poredak:  b<=a,b<c => b,a,c ili b,c,a */
         min=b;
      else     /* poredak: b<=a, c<=b => c,b,a */
         min=c;
      
   printf("Minimum unetih brojeva (1.nacin) je %d\n",min);
   
   /* 2. nacin */
   /* najpre odredimo minimum brojeva a,b*/
   if (a<b)
      min1=a;
   else 
      min1=b;
      
   if (c<min1)
      min1=c;
   printf("Minimum unetih brojeva (2.nacin) je %d\n",min1);
   
   /* 3. nacin */
   min2=a;
   if(min2>b) 
      min2=b;
   if(min2>c) 
      min2=c;
   
    printf("Minimum unetih brojeva (3.nacin) je %d\n",min2);
    
    cena_bez_popusta=a+b+c;
    cena_sa_popustom = cena_bez_popusta - min2 + 1;
   
    printf("Cena sa popustom: %.2f\n Cena bez popusta: %d\n Usteda: %.2f\n", cena_sa_popustom, cena_bez_popusta, cena_bez_popusta-cena_sa_popustom);
    
    return 0;
}