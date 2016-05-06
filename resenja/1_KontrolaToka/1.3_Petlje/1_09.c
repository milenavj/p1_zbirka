/* Niz prirodnih brojeva formira se na sledeci nacin:
an+1 = an/2 ako je an parno
an+1 = (3*an+1)/2 ako je an neparno
Napisati program koji za uneti pocetni clan niza a0 stampa niz brojeva sve do prvog clana jednakog
1.
*/
#include<stdio.h>
int main()
{
	int a0;
	int an,an1;  
	
	printf("Unesi pocetni clan niza brojeva:");
	scanf("%d",&a0);

	if (a0>0)
	{
		printf("%d\n", a0);	
		
		an=a0;
		while(an!=1)
		{
			if (an%2) /* ukoliko je vrednost izraza an%2 razlicita od nule,*/ 
			{         /* izraz se tumaci kao tacan i izvrsavaju se naredbe iz if grane */
				an1=(3*an+1)/2;
			}
			else /* u suprotnom, ukoliko je vrednost izraza an%2 jednaka nuli, izraz */
			{    /* se tumaci kao netacan i izvrsavaju se naredbe iz else grane */
				an1=an/2;
			}
			printf("%d\n",an1);
			an=an1; 		
		}
	}
	else
	   printf("Nekorektan unos\n");
	   
	return 0;
}
