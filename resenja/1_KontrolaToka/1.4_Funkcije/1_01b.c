#include <stdio.h>

int kub(int a)
{
   /* U listi argumenata funkcije moze, a ne mora, postojati promenljiva istog naziva kao promenljiva koja je deklarisana u main funkciji (u ovom slucaju promenljiva a). Ova promenljiva se razlikuje od promenljive a deklarisane u main funkciji i vidljiva je samo unutar funkcije kub. */
   return a*a*a;
}

int main()
{
   int a, kb;
   printf("Unesi ceo broj:");
   scanf("%d",&a);
   
   /* Promenljivoj kb se dodeljuje povratna vrednost funkcije kub. */
   kb = kub(a);     
   
   printf("Kub broja %d je %d\n", a, kb);
   return 0;
}
