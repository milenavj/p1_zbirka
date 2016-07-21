/* Sa standradnog ulaza unose se realan broj x i ceo broj n. Napisati
program koji izracunava x^n */

#include <stdio.h>

int main(void){

    int n, n_abs;
    float x;
    float vrednost;
    unsigned exp;
    
    /* Ucitavaju se brojevi x i n */
    printf("Unesite redom brojeve x i n: ");
    scanf("%f %d", &x, &n );

    /* Pocetna vrednost stepena koji se racuna */
    vrednost=1;

    /* Stepenovanje */
    n_abs=abs(n);
    for(exp=1; exp<=n_abs; exp++)
        vrednost=vrednost*x;
   
    /* Stampamo rezultat */
    if(n<0){
      printf("%.3f\n",1/vrednost);
    }
    else{
      printf("%.3f\n",vrednost);
    }
    
    return 0;
}
