#include <stdio.h>

int main()
{
  /* Promenljiva i kontrolise koliko puta ce se petlja izvrsiti i naziva se brojac petlje. 
     Njenu pocetnu vrednost postavljamo na 0 jer se u pocetku petlja nije ni jednom izvrsila. */
	int i = 0;

  /* Pre ulaska u telo petlje proverava se da li je 
		 ispunjen uslov ulaska u petlju.
  */
	while(i < 5)
  {
		/* Ukoliko uslov ulaska u petlju jeste ispunjen, izvrsava se telo petlje. */
    /* Ispisujemo trazeni tekst. */
		printf("Mi volimo da programiramo.\n");

    /* Uvecava se brojac za jedan jer je jednom izvrseno telo petlje. 
       Ako bi ova vrednost ostala nepromenjena, petlja bi se izvrsavala beskonacno. */
    i++;

		/* Nakon poslednje naredbe tela petlje ponovo se ispituje uslov petlje.*/

  }

	return 0;
}
