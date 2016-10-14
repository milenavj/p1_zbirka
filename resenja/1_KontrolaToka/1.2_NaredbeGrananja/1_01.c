
#include<stdio.h>

int main()
{
   int sati;
   int minuti;
   int preostali_sati;
   int preostali_minuti;
   
   /*
      Ukoliko naredbu printf zelimo da napisemo u dva
      reda, i tom prilikom prekidamo deo pod navodnicima,
      to mozemo uraditi navodjenjem navodnika na kraju
      prvog i na pocetku narednog reda:
   */
   
   printf("Unesite vreme (broj sati u itervalu [0,24),\n" 
           "broj minuta u intervalu [0,60)):");
   scanf("%d%d",&sati,&minuti);
   
   /* 
      U slucaju da je unos neispravan, ispisujemo
      poruku o gresci i prekidamo dalje izvrsavanje
      programa.   
   */
   
   if (sati>24 || sati<0 || minuti>59 || minuti<0)
   {
      printf("Neispravan unos.\n");
      return -1;
   }

   preostali_sati = 24-sati-1;
   preostali_minuti = 60-minuti;
   
   if (preostali_minuti==60)
   {
      preostali_sati++;
      preostali_minuti=0;
   }   
   
   /*
      Ukoliko naredbu printf zelimo da napisemo u dva
      reda i pritom ne prekidamo deo pod navodnicima,
      to mozemo uraditi bez navodjenja dodatnih karaktera:
   */
   printf("Do ponoci je ostalo %d sati i %d minuta\n",
           preostali_sati, preostali_minuti);
   return 0;
}