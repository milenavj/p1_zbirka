#include <stdio.h>

int main()
{
    int broj;
    scanf("%d", &broj);

    // Da bismo lakse odredili da li je cetvorocifren
    int absBroj = broj < 0 ? -broj : broj;
    if ( absBroj <= 999 || absBroj >= 10000)
    {
        printf("Broj nije cetvorocifren.");
        return -1;
    }

    int a = absBroj % 10;
    int b = (absBroj / 10) % 10;
    int c = (absBroj / 100) % 10;
    int d = absBroj / 1000;

    int max = a, min = a;
    // cuvamo i stepen da bismo lakse zamenili cifre
    /* Ideja:
       4179, mesta menjamo tako sto oduzmemo 9 i dodamo 1, 
        ^ ^  odnosno oduzemo 100 i dodamo 900 */
    int stepenMax = 1, stepenMin = 1;

    if (b > max) 
    {
        max = b;
        stepenMax = 10;
    }
    if (b < min) 
    {
        min = b;
        stepenMin = 10;
    }
        
    if (c > max)
    {
        max = c;
        stepenMax = 100;
    }
    if (c < min)
    {
        min = c;
        stepenMin = 100;
    }

    if (d > max)
    {
        max = d;
        stepenMax = 1000;
    }
    if (d < min)
    {
        min = d;
        stepenMin = 1000;
    }
        

    int rez;
    /* Ideja:
       4179, mesta menjamo tako sto oduzmemo 9 i dodamo 1, 
        ^ ^  odnosno oduzemo 100 i dodamo 900 */
    
    if (broj > 0)
        rez = broj - max*stepenMax + min*stepenMax
                   - min*stepenMin + max*stepenMin;
    else 
        rez = broj + max*stepenMax - min*stepenMax
                   + min*stepenMin - max*stepenMin;

    printf("%d\n",rez);

    return 0;
}
