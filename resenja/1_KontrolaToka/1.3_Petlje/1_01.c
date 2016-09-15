#include<stdio.h>

int main()
{
   /* Promenljiva i kontrolise koliko puta ce se petlja izvrsiti. Najcesce ovakvu promenljivu nazivamo "brojac". */
   int i=0;      
    /* Promenljiva koja oznacava koliko puta cemo ispisati trazeni tekst. */
   int n;       

	 printf("Unesite ceo broj: ");
 	 scanf("%d", &n);

   /* Pre ulaska u telo petlje proverava se da li je ispunjen uslov petlje. */
   while (i<n) 
	 {
       printf("Mi volimo da programiramo.\n");
       i++; 
   }
   return 0;
}
