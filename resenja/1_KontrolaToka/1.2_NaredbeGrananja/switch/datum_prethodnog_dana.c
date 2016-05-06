/* Napisati program koji za korektno unet datum u formatu dan.mesec.godina.
ispisuje datum prethodnog dana. */

#include <stdio.h>

int main(){
    int dan, mesec, godina;
    int prethodni_dan, prethodni_mesec, prethodni_godina;
    
    /* Citamo datum */
    printf("Unesite datum: ");
    scanf("%d.%d.%d", &dan, &mesec, &godina);
    
    /* Racunamo dan, mesec i godinu prethodnog dana */
    prethodni_dan=dan-1;
    prethodni_mesec=mesec;
    prethodni_godina=godina;
    
    /* I po potrebi vrsimo korekcije */
    
    /* Ako je u pitanju prvi u mesecu */
    if(prethodni_dan==0){
        /* Treba korigovati mesec */
        prethodni_mesec=mesec-1;
        /* Ako je u pitanju januar */
        if(prethodni_mesec==0){
            /* Treba korigovati i godinu */
            prethodni_mesec=12;
            prethodni_godina=godina-1;
        }
        
        /* Analiziramo redni broj meseca kako bi odredili tacan dan*/
        switch(prethodni_mesec){
          case 1: 
          case 3: 
          case 5: 
          case 7: 
          case 8: 
          case 10: 
          case 12:
            prethodni_dan=31;
            break;
          case 2:
            if((prethodni_godina%4==0 && prethodni_godina%100!=0) ||
                    prethodni_godina%400==0)
                prethodni_dan=29;
            else
                prethodni_dan=28;
            break;
          case 4: 
          case 6: 
          case 9: 
          case 11:
            prethodni_dan=30;
        }
    }

    /* Ispisujemo datum koji smo izracunali */
    printf("Prethodni datum: %d.%d.%d\n", 
           prethodni_dan, prethodni_mesec,prethodni_godina);
    
    return 0;
}
