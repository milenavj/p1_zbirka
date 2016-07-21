/* Napisati program koji za dati trocifren broj proverava da li je
Amstrongov. Broj je Amstrongov ako je jednak zbiru kubova svojih cifara.
*/

#include <stdio.h>

int main(){
  int n, j, d, s;
  
  /* Ucitavamo broj */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Proveravamo da li je broj trocifren */
  if(n<100 || n>999){
    /* Ako broj nije trocifren, prijavljujemo gresku */
    printf("Greska: Niste uneli trocifren broj!\n");
  }
  else{
    
    /* Ako je broj trocifre, izdvajamo cifre broja:
      j -jedinice, d - desetice, s - stotine
    */
    j=n%10;
    d=(n/10)%10;
    s=n/100;
    
    /* Proveravamo da li je broj Amstrongov */
    if(n==j*j*j+d*d*d+s*s*s){
      printf("Broj je Amstrongov.\n");
    }
    else{
      printf("Broj nije Amstrongov.\n");
    }
  }
   
  return 0;

}