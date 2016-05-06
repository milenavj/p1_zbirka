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

int kub(int a)
{
   /*
      u listi argumenata funkcije mozemo, a ne moramo, imati promenljivu
      istog naziva kao promenljiva koja je deklarisana u main funkciji
      (u ovom slucaju promenljiva a); ova promenljiva se razlikuje
      od promenljive a deklarisane u main funkciji i vidljiva je
      samo unutar funkcije kub      
   */
   return a*a*a;
}

int main()
{
   int a,kv, kb;
   printf("Unesi ceo broj:");
   scanf("%d",&a);
   
   kv = kvadrat(a); /* promenljivoj kv dodeljujemo povratnu vrednost funkcije kvadrat */
   kb = kub(a);     /* promenljivoj kb dodeljujemo povratnu vrednost funkcije kub */
   
   printf("Kvadrat broja %d je %d, a njegov kub je %d\n", a, kv, kb);
   return 0;
}