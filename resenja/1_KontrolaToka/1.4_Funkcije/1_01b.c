#include <stdio.h>

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
   int a, kb;
   printf("Unesi ceo broj:");
   scanf("%d",&a);
   
   kb = kub(a);     /* promenljivoj kb dodeljujemo povratnu vrednost funkcije kub */
   
   printf("Kub broja %d je %d\n", a, kb);
   return 0;
}