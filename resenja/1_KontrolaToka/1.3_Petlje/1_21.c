#include <stdio.h>

int main()
{
  /* Promenljiva i kontrolise koliko puta ce se petlja izvrsiti. 
     Njenu pocetnu vrednost postavljamo na 0 jer se u pocetku petlja nije ni jednom izvrsila. */
	int i = 0;

  /* Pre ulaska u telo petlje proverava se da li je 
		 ispunjen uslov petlje.
  */
	while(i < 5)
  {
		/* Ukoliko uslov petlje jeste ispunjen ulazimo u telo petlje. */
    /* Ispisujemo trazeni tekst. */
		printf("Mi volimo da programiramo.\n");

		/* Uvecavamo promenljivu za jedan jer smo jednom prosli kroz petlju. */
    i++;

		/* Nakon poslednje naredbe tela petlje ponovo se vracamo na ispitivanje uslova petlje. 
       Ako ovu vrednost ne menjamo dobicemo petlju koja se izvrsava beskonacno. */
  }

	return 0;
}
