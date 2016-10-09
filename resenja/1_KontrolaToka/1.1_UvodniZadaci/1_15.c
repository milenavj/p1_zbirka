#include <stdio.h>

int main()
{

   unsigned broj, novibroj;
   unsigned levi, desni, m;
   
   printf("Unesite pozitivan prirodan broj: ");
   scanf("%u", &broj);
   printf("Unesite pozitivan dvocifreni broj:");
   scanf("%u", &m);
   
   /*
      Na primer, za unete broj 12345 i 67, potrebno je ubaciti 
      67 izmedju cifre hiljade (2) i cifre stotine (3). Rezultat 
      je 12|67|345. Potrebno je da razdvojimo uneti broj na levi 
      i desni deo: 12 i 345 i izmedju njih umetnemo broj m
   */
   
   levi = broj/1000;
   desni = broj%1000;
   
   /*
      Kada levi deo pomnozimo sa 100 000, dobijamo 1 200 000
      Kada m pomnozimo sa 1000, dobijamo              67 000
      Dobijene vrednosti saberemo sa desnim delom        345
                                                   ---------
      Konacan rezultat:                            1 267 345
      
   */      
   novibroj = levi*100000+m*1000+desni;
   
   printf("Novi broj je %u\n", novibroj);   

   return 0; 
}
