#include <stdio.h>
#include <math.h>

int main()
{
	unsigned int format;
	/* Pomocna promenljiva koja sluzi kao brojac u petlji. */
	int i;
	/* Trenutne vrednosti za sirinu i visinu i
	 * pomocna promenljiva za promene u petlji.
	 */
	double sirina, duzina, nova_duzina; 
	unsigned int konacna_sirina, konacna_duzina;

	printf("Uneti format papira: ");
	scanf("%u", &format);

	/* duzina/sirina = 1 : sqrt(2) duzina*sirina = 1000x1000mm^2
	 * Na osnovu ovih odnosa dobijamo pocetnu vrednost za sirinu 
	 * i duzinu, odnosno vrednosti za papir A0.
	 */
	 duzina = sqrt(1000*1000/sqrt(2));
	 sirina = sqrt(2)*duzina;
	 
	 /* Kako vec imamo odredjenu sirinu i duzinu za papir A0,
	  * petlju krecemo od izracunavanja za papir A1, pa 
	  * brojac i postavljamo na 1.
	  */
	 for(i=1; i<=format; i++)
	 {
		 nova_duzina = sirina/2;
		 sirina = duzina;
		 duzina = nova_duzina;
	 }
	 
	 /* Duzina i sirina celi brojevi. */
	 konacna_sirina = (unsigned int)sirina;
	 konacna_duzina = (unsigned int)duzina;
	 
	 printf("%u %u\n", konacna_duzina, konacna_sirina);

	return 0;
}
