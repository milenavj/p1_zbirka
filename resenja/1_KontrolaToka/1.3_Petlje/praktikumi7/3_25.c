#include <stdio.h>

int main(){

	int n, i, j;

	printf("Unesite broj n: ");
	scanf("%d", &n);
	
	/* Krstice koje iscrtavamo mozemo posmatrati kao dijagonale kvadrata dimenzije n */
		
	/* Prolazimo kroz sve vrste kvadrata */
	for(i=1; i<=n; i++){
	
		/* Prolazimo kroz sve kolone kvadrata */
		for(j=1; j<=n; j++){
		
			/* Ako se nalazimo na glavnoj ili sporednoj dijagonali */
			if(i==j || i+j==n+1)
				/* Stampamo zvezdu */
				putchar('*');
			else
				/* Inace, stampamo blanko znak */
				putchar(' ');
		}
		
		/* Nakon uspesno iscrtane vrste, stampamo znak za novi red */
		putchar('\n');
	}
	
	return 0;
}
