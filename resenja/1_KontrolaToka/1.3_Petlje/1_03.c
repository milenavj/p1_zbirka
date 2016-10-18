#include<stdio.h>

int main()
{
    int x;
    /* U promenljivoj f se pamti izracunati faktorijel. 
     * Kako faktorijel je jako veliki broj, za tip podataka
     * se uzima unsigned long, da bi mogla da se upise 
     * sto veca vrednost. */
    unsigned long f;
    int i;
    int original;

    printf("Unesite pozitivan broj: ");
    scanf("%d",&x);

    if (x < 0)
    {
        printf("Nekorektan unos\n");
        return -1;
    }
    
    if (x >= 22)
    {
        printf("Broj je veliki, dolazi do prekoracenja.\n");
        return -1;
    }

    original=x;
    f=1;

    while (x>1)
    {
        f=f*x; 
        x--;  
    }
    
    printf("Faktorijel = %lu\n", f); 

  

  return 0;
}