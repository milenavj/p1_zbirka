/*
   Napisati program koji za uneti ceo broja n ispisuje n puta tekst
   "We love C programming" koriscenjem while, for i do while petlje. Obratiti paznju
   na rezultat kada je n<=0. 
*/

#include <stdio.h>

int main()
{

   int n,m;
   int i;
   
   printf("Unesi ceo broj:");
   scanf("%d",&n);
   
   /* 1. nacin - while petlja */
   printf("while: ");   
   
   i=0;
   while (i<n)          /* uslov petlje se proverava pre ulaska u telo petlje */   
   {
      printf("We love C programming\n");
      i++;
   }
   
   printf("\n");
   
   /* 2. nacin - for petlja */
   printf("for: ");   
                          /* naredba i=0 se izvrsava jednom, pre prve iteracije */
   for(i=0;i<n;i++)      /* uslov petlje i<=m se proverava pre svake iteracije */
      printf("We love C programming\n");   /* naredba i++ se izvrsava nakon svake iteracije */
   
   printf("\n");
   
   /* 3. nacin - do while petlja */
   printf("do while: ");  /* uslov petlje se proverava na kraju svake iteracije */ 
                          /* zbog toga se do while petlja izvrsava bar jednom, cak i u slucaju */
                          /* da uslov petlje nikada nije ispunjen */ 
   i=0;
   do                                     /* petlja se zapocinje bez provere uslova */
   {
      printf("We love C programming\n");  /* stampa se dati tekst */
      i++;                                /* uvecava se vrednost promenljive i */
   }
   while(i<n);                            /* proverava se uslov i ukoliko je ispunjen, nastavlja se sa sledecom iteracijom */
                                          /* u suprotnom, petlja se zavrsava i program se nastavlja od prve naredbe koja sledi za petljom */
   printf("\n");
   
   return 0;

}