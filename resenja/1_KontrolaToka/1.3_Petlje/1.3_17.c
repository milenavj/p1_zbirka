#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, cifra;
    int indikator=0;

    /* Ucitavamo broj. */
    printf("Unesite broj: ");
    scanf("%d", &n);
    
    if (n < 0)
      n = abs(n);
    
    /* Sve dok imamo cifara u zapisu broja. */
    while(n>0){
 
      /* Izdvajamo posledjnju cifru broja. */
      cifra=n%10;
      
      /* Proveravamo da li je bas ona jednaka broju 5 */
      if(cifra==5){
        /* Ako jeste postavljamo indikator na vrednost 1 tako da znamo
         * da smo pronasli peticu i prekidamo sa izvrsavanjem petlje. 
         */
        indikator=1;
        break;
      }
      /* Ako izvdvojena cifra nije jednaka broju 5, broj delimo sa 10 
       * kako bi mogli da izdvojimo i preostale cifre broja na isti 
       * nacin. 
       */
      n=n/10;
    }
    
    /* Ispisujemo rezultat */
    if(indikator==0){
      printf("Cifra 5 se ne nalazi u zapisu!\n");
    }
    else{
      printf("Cifra 5 se nalazi u zapisu!\n");
    }
    
    return 0;
}
