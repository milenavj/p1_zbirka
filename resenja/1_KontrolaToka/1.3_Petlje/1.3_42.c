#include <stdio.h>
#include <math.h>
int main(){
    /* Promenljiva i je brojac, promenljiva S cuva izracunatu sumu,
     * a promenljiva clan je tekuci clan niza. */
    int i;
    float  S;
    float x, eps;
    float clan;
    
    printf("Unesite x: ");
    scanf("%f", &x);
    
    printf("Unesite tacnost eps: ");
    scanf("%f", &eps);
    
    S=0;
    /* Prvi clan sume je 1. */
    clan = 1;
    i=1;
    while(clan > eps){
        S=S+ clan;
        clan = clan*x / i;
        i++;
    }
    
    printf("S=%f\n", S);
    
    return 0;
}
