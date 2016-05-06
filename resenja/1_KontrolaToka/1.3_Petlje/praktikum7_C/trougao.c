#include <stdio.h>

int main(){

	int n;
	char novi_red, c;
	int i, j;

	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	scanf("%c", &novi_red);
	
	printf("Unesite karakter c: ");
	scanf("%c", &c);
	
	/* Iscrtavamo trougao red po red */
	for(i=1; i<=n; i++){
	
		/* Ukoliko je u pitanju prvi ili poslednji red */
		if(i==1 || i==n){
			/* Stampamo i puta karakter c */
			for(j=1; j<=i; j++)
				putchar(c);
		}
		else{
			/* Inace... */
			
			/* Stampamo prvi karakter */
			putchar(c);
		
			/* Stampamo i-2 blanko znaka */
			for(j=1; j<=i-2; j++)
				putchar(' ');
			
			/* Stampamo poslednji karakter */
			putchar(c);
		}
		
		/* Stampamo znak za novi red */
		printf("\n");
	}
	
	return 0;
}
