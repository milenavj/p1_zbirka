
#include <stdio.h>
int main()
{
   int x;
   int cifra_jedinice;
   int cifra_desetice;
   int cifra_stotine;
   
   printf("Unesi trocifreni broj:");
   scanf("%u", &x);
   
   /* 
      Na primer, neka je uneti broj 374. Potrebno je da koriscenjem 
      racunskih operacija za rad sa celim brojevima pristupimo 
      njegovoj cifri jedinice, cifri desetice i cifri stotine.
      
      Primetimo najpre sledece:
      374/10 = 37
      374%10 = 4
      Dakle, operacijama celobrojnog deljenja i ostatka pri deljenju 
      mozemo iz svakog broja izdvojiti njegovu poslednju cifru (u 
      ovom slucaju 4) i broj sastavljen od svih cifara osim poslednje 
      (u ovom slucaju 37).
      
      Cifri jedinice sada lako pristupamo koriscenjem ostatka pri 
      deljenju sa 10. Ona iznosi upravo 4.
      
      Pri trazenju cifre desetice mozemo ponovo primeniti princip 
      izdvajanja poslednje cifre kao ostatka pri deljenju sa 10. 
      Razlika je sto ne mozemo deseticu izdvojiti ako primenimo %10 
      na 374 (time dobijamo 4), vec %10 primenjujemo na 37, pri cemu
      37 dobijamo kao ceo deo pri deljenju broja 374 brojem 10. 
      Dakle, cifru desetice dobijamo kao (374/10)%10.
      
      S obzirom da znamo da je u pitanju trocifreni broj, cifru 
      stotine mozemo izdvojiti celobrojnim deljenjem sa 100: 374/100 
      iznosi upravo 3.

    */
   cifra_jedinice = x%10;
   cifra_desetice = (x/10)%10;
   cifra_stotine = x/100;
   
   printf("jedinica %d, desetica %d, stotina %d\n", cifra_jedinice, 
                                                    cifra_desetice, 
                                                    cifra_stotine);
   
   /*
      2. nacin, bez uvodjenja dodatnih promenljivih cifra_jedinice,
      cifra_desetice i cifra_stotine:
	 
      printf("Cifre unetog broja su %d,%d,%d\n", x%10, (x/10)%10, x/100);
   */
   return 0;
}