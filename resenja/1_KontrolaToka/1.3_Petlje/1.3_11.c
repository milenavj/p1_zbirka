#include <stdio.h>

int main()
{
	/* Prirodni broj koji se unosi. */
	int n;
	/* Promenljiva u koju se smesta suma cifara broja. */
	int suma = 0;
	/* Pomocna promenljiva u koju se smesta unesen broj. */
	int pom_n;
	
	printf("Unesi broj ");
	scanf("%d", &n);
	
	/* U zadatku pise da se unosi prirodan broj,
	 * sto znaci da treba proveriti da li je veci
	 * od 0
	 */
	 
	if (n <= 0)
	{
		printf("Neispravan unos.\n");
		return -1;
	}
	
	/* Potrebno je koristiti pomocnu promenljivu jer u telu petlje
	 * se odstranjuju cifre broja i na taj nacin uneseni broj
	 * se menja. Nakon rada petlje potrebno je ponovo koristiti
	 * uneseni broj, a to znaci da treba sacuvati neizmenjen
	 * broj.
	 */
	pom_n = n;
	
	while(pom_n != 0)
	{
		/* Na sumu dodajemo poslednju cifru. */
		suma += pom_n % 10;
		/* Sa broja skidamo poslednju cifru. */
		pom_n /= 10;
	}
	
	if (n % suma == 0)
		printf("Deljiv je sumom svojih cifara.\n");
	else
		printf("Nije deljiv sumom svojih cifara.\n");
	
	return 0;
}
