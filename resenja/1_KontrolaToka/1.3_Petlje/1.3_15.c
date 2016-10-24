#include <stdio.h>

int main()
{
    /* Promenljiva cena oznacava trenutno unesenu cenu. */
    float cena;
    float m;
    int n, i;
    int broj_brojeva=0;

    printf("Unesite koliko novaca ima Nikola: ");
    scanf("%f", &m);
    
    if (m < 0)
    {
      printf("Nikola ne moze imati negativno novaca.\n");
      return -1;
    }

    printf("Unesite broj artikala: ");
    scanf("%d", &n);
    
    if (n < 0)
    {
      printf("Broj artikala ne moze biti negativan.\n");
      return -1;
    }
    
    printf("Unesite cene artikala: ");
    
    i=0;
    while(i<n){
        /* Ucitava se cena artikla. */
        scanf("%f", &cena); 
        
	if (cena <= 0)
	{
	  printf("Cena ne moze biti negativna.\n");
	  return -1;
	}
	
        /* Provera da li je cena manji od zadatog broja m. */
        if(cena < m){
            /* Ako jeste, uvecava se brojac brojeva za 1. */
            broj_brojeva++;
        }
        
        i++;    
    }
    
    printf("%d\n", broj_brojeva);
    
    return 0;
}
