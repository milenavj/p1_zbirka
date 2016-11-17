#include <stdio.h>

int main () {
    /* Promenljiva i je brojac , promenljiva S cuva izracunatu sumu ,
    promenljiva znak moze bito 1 ili -1 i odredjuje znak trenutnog
    clana sume , a promenljiva clan je tekuci clan niza. */

    int i, znak , n;
    float S;
    float x, clan;
    printf(" Unesite x i n: ");
    scanf("%f%d", &x, &n);

    if (n <= 0) {
        printf(" Neispravan unos .\n");
        return -1;
    }

    S = 1;
    clan = 1;
    i = 1;
    znak = -1;

    /* Kako clanovi sume mogu biti negativni , potrebno je posmatrati
    apsolutnu vrednost clana. */
    while (i <= 2 * n - 1) {

        /* Promena znaka. */
        /* Svaki clan suma se od prethodnog clana razlikuje za
        x^2/(i*(i+1)). */
        clan = clan * x * x / (i * (i + 1));
        clan *= znak;
        
        S = S + clan;

        i += 2;
    }

    printf("S=%f\n", S);

    return 0;
}