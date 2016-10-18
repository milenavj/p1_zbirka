#include <stdio.h>

int main()
{
    int n, i;
    double Razlomak;
    
    printf("Unesite prirodan broj: ");
    scanf("%d", &n);
    
    if (n <= 0)
    {
        printf("Neispravan unos.\n");
        return -1;
    }
    
    Razlomak = n;
    
    /* Razlomak se izracunava "od nazad", odnosno, krece se
     * od najnizeg razlomka 1/n i od njega se nadalje formira
     * sledeci, "visi" razlomak itd. Zavrsava se kada se stigne
     * do koraka 0 + 1/R. */
    for(i=n-1; i>= 0; i--)
        Razlomak = i + 1/Razlomak;
    
    printf("Razlomak = %lf\n", Razlomak);
    
    return 0;
}