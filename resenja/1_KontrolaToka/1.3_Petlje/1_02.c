#include <stdio.h>

int main()
{
   /* Promenljivu x koristimo u dve svrhe. Prvo, ova promenljiva kontrolise koliko puta se petlja izvrsila.
      Drugo, ovu promenljivu koristimo za ispis potrebnih vrednosti. */
   int x; 
   /* Promenljiva n se unosi i odredjuje koliko brojeva ispisujemo. */
   int n;
   
   printf("Unesi pozitivan ceo broj: ");
   scanf("%d", &n);

	 /* U slucaju neispravnih podataka ispisujemo odgovarajucu poruku
      i izlazimo iz programa. */
	 if (n < 0)
   {
		 printf("Neispravan unos. Promenljiva mora biti pozitivna!\n");
     return -1;
	 }

	 /* Ispis pocinjemo od 0, zato promenljivu x postavljamo na 0. */
   x=0;
   while (x<= n)
   { 
       /* Ispisujemo broj. */
       printf("%d\n", x);
			 /* Uvecavamo promenljivu za jedan jer smo broj ispisali i sada zelimo da ispisemo sledeci broj. */
       x++; 
   }
   return 0;
}
