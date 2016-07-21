/* Sa standardnog ulaza unosi se realan broj m, ceo pozitivan broj n i n realnih
brojeva. Izracunati i ispisati koliko je brojeva medju unetima manje od zadatog
broja m. */

#include <stdio.h>

int main(){
  
    float m, x;
    int n, i;
    int broj_brojeva=0;

    printf("Unesite broj m: ");
    scanf("%f", &m);

    printf("Unesite broj n: ");
    scanf("%d", &n);
    
    printf("Unesite n brojeva: ");
    /* Inicijalizujemo brojac kojim kontrolisemo broj ucitavanja - 
     * treba da ih bude tacno n
     */
    i=0;
    while(i<n){
        /* Ucitavamo broj */
        scanf("%f", &x); 
        
        /* Proveravamo da li je broj manji od zadatog broja m */
        if(x<m){
            /* Ako jeste, uvecavamo brojac brojeva za 1 */
            broj_brojeva++;
        }
        
        /* Uvecavamo brojac iteracija */
        i++;    
    }
    
    /* Ispisujemo rezultat */
    printf("%d\n", broj_brojeva);
    
    return 0;
}
