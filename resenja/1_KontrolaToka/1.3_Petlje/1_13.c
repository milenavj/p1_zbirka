#include <stdio.h>

int main()
{
    int n;
    /* Brojac. */
    int i;
    /* Promenljiva u kojoj se cuva suma kubova. */
    int s;


    printf("Unesite pozitivan ceo broj:");
    scanf("%d", &n);

    if (n < 0)
    {
        printf("Neispravan unos.\n");
        return -1;
    }

    i=1;
    s=0; 

    for(i=1;i<=n;i++)
        s+=i*i*i;
        

    printf("Suma kubova od 1 do %d: %d\n", n, s);
    return 0;
}
