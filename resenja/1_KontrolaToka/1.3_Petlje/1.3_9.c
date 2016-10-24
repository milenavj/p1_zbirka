#include <stdio.h>

int main(){
    int n;

    /* Ucitavamo broj */
    printf("Unesite broj: ");
    scanf("%d", &n);
   
    if(n==0){
      printf("0\n");
    }
    else{
      /* Sve dok je poslednja cifra u zapisu broja n nula */
      while(n%10==0){
        /* Broj delimo sa 10 tj. uklanjamo mu nulu sa kraja */
        n=n/10;
      }
      
      /* Ispisujemo rezultat */
      printf("%d\n", n);
    }
    
    
    return 0;
}
