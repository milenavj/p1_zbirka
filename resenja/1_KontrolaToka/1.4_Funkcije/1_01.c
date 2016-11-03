#include <stdio.h>

int kvadrat(int x) 
{
   /* promenljive u listi argumenata funkcije, kao i one
      deklarisane u samoj funkciji, lokalne su za tu funkciju
      sto znaci da se promenljive x i y nece "videti" nigde izvan
      funkcije kvadrat (ni u funkciji main ni u funkciji kub)
   */
   
   int y;
   y = x*x;
   return y;
}

int main()
{
   int a,kv, kb;
   printf("Unesi ceo broj:");
   scanf("%d",&a);
   
   kv = kvadrat(a); /* promenljivoj kv dodeljujemo povratnu vrednost funkcije kvadrat */
   
   printf("Kvadrat broja %d je %d\n", a, kv);
   return 0;
}