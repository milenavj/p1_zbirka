/* Resenje pod a). */

#include <stdio.h>
#include <stdlib.h>

int main()
{
   /* Promenljive koje oznacavaju granice intervala. */
   int n,m;
   /* Promenljiva koja oznacava trenutno ispisani broj intervala. */
   int i; 
   
   printf("Unesi dva cela broja: ");
   scanf("%d%d",&n,&m);

	 if (m < n)
   {
		 printf("Neispravan unos. Nisu dobro zadate granice intervala!\n");
     exit(EXIT_FAILURE);
   }
   
   /* Na pocetku ispisujemo prvi broj intervala, a to je n. */
   i=n;
   /* uslov petlje se proverava pre ulaska u telo petlje */
   while (i<=m)             
   {
      printf("%d ", i);
      i++;
   }
   
   printf("\n");
   
   
   return 0;
}
