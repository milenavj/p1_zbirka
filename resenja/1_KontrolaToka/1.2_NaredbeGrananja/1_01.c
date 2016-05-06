/*
   Napisati program koji za uneto vreme ispisuje koliko je sati i minuta ostalo
   do ponoci. 
*/
#include<stdio.h>

int main()
{
   int sati;
   int minuti;
   int preostali_sati;
   int preostali_minuti;
   
   printf("Unesi vreme (broj sati u itervalu [0,24), broj minuta u intervalu [0,60)):");
   scanf("%d%d",&sati,&minuti);
   
   preostali_sati = 24-sati-1;
   preostali_minuti = 60-minuti;
   if (preostali_minuti==60)
   {
      preostali_sati++;
      preostali_minuti=0;
   }   
   
   printf("Do ponoci je ostalo %d sati i %d minuta\n", 24-sati-1, 60-minuti);
   return 0;
}