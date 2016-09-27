#include<stdio.h>

int main()
{
   /* Brojac u petlji. */
   int i=0;      
    /* Promenljiva koja oznacava koliko puta cemo ispisati trazeni tekst. */
   int n;       

	 printf("Unesite ceo broj: ");
 	 scanf("%d", &n);

   /* Pre ulaska u telo petlje proverava se da li je ispunjen uslov ulaska u petlju. */
   while (i<n) 
	 {
       printf("Mi volimo da programiramo.\n");
       i++; 
   }
   return 0;
}
