/*
Program izracunava minimum n unetih brojeva. 
Npr. za n=4 i brojeve 3 8 2 9 program ispisuje 2
*/
#include <stdio.h>
int main()
{
    int n, i;
    float x, min;


    printf("Unesi n>0:");
    scanf("%d", &n);
    if (n<=0)                        /* ako je unos neispravan */
    {
        printf("Neispravan unos\n");
        return -1;                   /* prekidamo izvrsavanje programa pomocu naredbe return */
    }                                /* u slucaju greske kao sto je neispravan unos vracamo vrednost -1 */
    printf("Unesi realan broj:");
    scanf("%f", &x);           /* prvi broj je unet izvan petlje */
    min=x;                     /* kako bi bio njegova vrednost bila dodeljena promenljivoj min */
                               /* neophodno je da promenljiva min bude inicijalizovana pre ulaska u petlju */
                               /* da bi uslov x<min mogao da bude ispitan u prvoj iteraciji */
    i=0;
    while(i<(n-1))
    {
      printf("Unesi realan broj:");
      scanf("%f", &x);
      if(x<min)
         min=x;
      i++;
    }
    printf("Minimum je: %f\n", min);
    return 0;
}

