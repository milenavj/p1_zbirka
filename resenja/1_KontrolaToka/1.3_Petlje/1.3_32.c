#include<stdio.h>
int main()
{
	int a0;
	int an,an1;  
	
	printf("Unesi pocetni clan niza brojeva:");
	scanf("%d",&a0);

	if (a0 <= 0)
	{
		printf("Nekorektan unos. Broj mora biti pozitivan.\n");
		return -1;
	}

	printf("%d\n", a0);	
	
	an=a0;
	while(an!=1)
	{
		if (an%2) /* Ukoliko je vrednost izraza an%2 razlicita od nule,*/ 
		{         /* izraz se tumaci kao tacan i izvrsavaju se naredbe iz if grane. */
			an1=(3*an+1)/2;
		}
		else /* U suprotnom, ukoliko je vrednost izraza an%2 jednaka nuli, izraz */
		{    /* se tumaci kao netacan i izvrsavaju se naredbe iz else grane. */
			an1=an/2;
		}
		printf("%d\n",an1);
		an=an1; 		
	}
	   
	   
	return 0;
}
