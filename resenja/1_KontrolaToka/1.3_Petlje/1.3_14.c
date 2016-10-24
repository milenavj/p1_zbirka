#include <stdio.h>

int main()
{
    int n, broj;
    int suma = 0;
    /* Brojac. */
    int i;
    
    printf("Unesite broj n: ");
    scanf("%d", &n);
    
    if (n < 0)
    {
        printf("Neispravan unos.\n");
        return -1;
    }
    
    printf("Unesite brojeve: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &broj);
        
        if (broj % 5 == 0 && broj % 7 != 0)
            suma += broj;
    }
    
    printf("Suma je %d.\n", suma);
    
    return 0;
}