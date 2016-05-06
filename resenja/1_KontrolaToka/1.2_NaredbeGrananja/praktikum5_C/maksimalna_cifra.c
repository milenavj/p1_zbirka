/* Sa standardnog ulaza se unosi ceo cetvorocifren broj. Napisati program koji
ispisuje njegovu najvecu cifru na standardni izlaz. */

#include <stdio.h>

int main(){
  int n, j, d, s, h, max;
  
  /* Ucitavamo broj */
  printf("Unesite broj: ");
  scanf("%d", &n);
  
  /* Proveravamo da li se radi o cetvorocifrenom broju */
  if(n<1000 || n>9999){
    /* Ako broj nije cetvorocifren, prijavljujemo gresku */
    printf("Greska: Niste uneli cetvorocifren broj!\n");
  }
  else{
    
    /* Ako je broj cetvorocifren, izdvajamo cifre broja:
      j -jedinice, d - desetice, s - stotine i h - hiljade 
    */
    j=n%10;
    d=(n/10)%10;
    s=(n/100)%10;
    h=n/1000;
    
    /* Odredjujemo maksimalnu cifru */
    max=j;
    if(d>max)
      max=d;
    if(s>max)
      max=s;
    if(h>max)
      max=h;
    
    /* II nacin: 
     * if(j>d && j>s && j>h) 
     *  max=j;
     * if(d>j && d>s && d>h)
     *  max=d;
     * if(s>j && s>d && s>h)
     *  max=s;
     * if(h>j && h>d && h>s)
     *  max=h;
     */

    /* Ispisujemo rezultat */
    printf("Najveca cifra je: %d\n", max);
  
  }
  
  return 0;
}
