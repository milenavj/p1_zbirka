#include <stdio.h>

int main(){

	int n;		
	int k, v;	
	
	/* Unosi se dimenzija kvadrata */
	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	/* Kvadrat iscrtavamo vrstu po vrstu */
	for(v=1; v<=n; v++){
		
		/* Ukoliko je u pitanju prva ili poslednja vrsta */
		if(v==1 || v==n){
		
			/* Stampamo n zvezdica */
			for(k=1; k<=n; k++)
				putchar('*');
					
		}			
		else
		{
			/* Ukoliko vrsta nije ni prva ni poslednja */
			
			/* Stampamo prvu zvezdu */
			putchar('*');
			
			/* Zatim stampamo n-2 blanko znaka */
			for(k=1; k<=n-2; k++)
				putchar(' ');
						
			/* I stampamo poslednju zvezdu */
			putchar('*');
				
		}
		
		/* Posto smo odstampali sadrzaj vrste, stampamo i znak za novi red */
		putchar('\n');				
	}
		
	return 0;
}
