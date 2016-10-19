#include <stdio.h>
#include <stdlib.h> /*abs*/

int main()
{
  int n, j, d, s;
  
  /* Ucitavamo broj */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /*
    Uzimamo apsolutnu vrednost broja za slucaj da je
    uneti broj negativan
  */
  n = abs(n);
  
  /* 
    Ako broj nije trocifren, izdajemo poruku o gresci i 
    prekidamo dalje izvrsavanje programa
  */
  if(n<100 || n>999)
  {
    printf("Greska: Niste uneli trocifren broj!\n");
    return -1;
  }
    
  /* 
    Izdvajamo cifre broja:
    j -jedinice, d - desetice, s - stotine
  */
  j=n%10;
  d=(n/10)%10;
  s=n/100;
    
  /* Proveravamo da li je broj Amstrongov */
  if(n==j*j*j+d*d*d+s*s*s)
    printf("Broj je Amstrongov.\n");
  else
    printf("Broj nije Amstrongov.\n");
       
  return 0;
}
