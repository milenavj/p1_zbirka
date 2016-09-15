#include <stdio.h>

int main()
{

   int n,m;
   int i;
   
   printf("Unesi dva cela broja:");
   scanf("%d%d",&n,&m);
   
   /* 1. nacin - while petlja */
   printf("while: ");   
   
   i=n;
   while (i<=m)          /* uslov petlje se proverava pre ulaska u telo petlje */   
   {
      printf("%d ", i);
      i++;
   }
   
   printf("\n");
   
   /* 2. nacin - for petlja */
   printf("for: ");   
                          /* naredba i=n se izvrsava jednom, pre prve iteracije */
   for(i=n;i<=m;i++)      /* uslov petlje i<=m se proverava pre svake iteracije */
      printf("%d ", i);   /* naredba i++ se izvrsava nakon svake iteracije */
   
   printf("\n");
   
   /* 3. nacin - do while petlja */
   printf("do while: ");  /* uslov petlje se proverava na kraju svake iteracije */ 
                          /* zbog toga se do while petlja izvrsava bar jednom, cak i u slucaju */
                          /* da uslov petlje nikada nije ispunjen */ 
   i=n;
   do                   /* petlja se zapocinje bez provere uslova */
   {
      printf("%d ",i);  /* stampa se vrednost promenljive i */
      i++;              /* uvecava se vrednost promenljive i */ 
   } 
   while(i<=m);         /* proverava se uslov i ukoliko je ispunjen, nastavlja se sa sledecom iteracijom */
                        /* u suprotnom, petlja se zavrsava i program se nastavlja od prve naredbe koja sledi za petljom */
   printf("\n");
   return 0;
}
