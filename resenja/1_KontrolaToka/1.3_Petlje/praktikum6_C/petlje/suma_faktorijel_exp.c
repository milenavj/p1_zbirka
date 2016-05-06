/* Napisati program koji sa zadatom tacnoscu izracunava sumu
S=1+x+x^2/2!+x^3/3!+...+x^n/n! + ...*/
/* Napomena: ovo je razvoj funkcije e^x */

#include <stdio.h>
#include <math.h>
int main(){
    int n, i, faktorijel;
    float  S;
    float x, eps, stepen;
    
    printf("Unesite x: ");
    scanf("%f", &x);
    
    printf("Unesite tacnost eps: ");
    scanf("%f", &eps);
    
     
    /* Tacnost izracunavanja je zadovoljena ako je apsolutna vrednost 
     * razlika suma
     * u dvema uzastopnim iteracijama manja od zadate tacnosti; 
     * Odavde se izvodi da apsolutna vrednost opsteg clana sume 
     * mora da bude manja od zadate tacnosti da bi uslov bio ispunjen 
     */
    
    S=1;
    faktorijel=1;
    stepen=x;
    i=2;
    while(fabs(stepen/faktorijel)>eps){
        S=S+stepen/faktorijel;
        stepen=stepen*x;
        faktorijel=faktorijel*i;
        i++;
    }
    
    printf("S=%f\n", S);
    
    return 0;
}
