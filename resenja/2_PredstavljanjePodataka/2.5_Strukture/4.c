#include <stdio.h>
#include <string.h>
#define MAX_DUZINA 21
#define MAX_BR_RECI 100

typedef struct ParReci{
	char sr[MAX_DUZINA+1];
	char en[MAX_DUZINA+1];
}ParReci;


/* 
	Funkcija koja u recniku koji sadrzi n reci trazi prevod reci rec i upisuje ga u prevod.
	Ukoliko se rec ne nalazi u recniku, prevod se sastoji od zvezdica pri cemu broj zvezdica odgovara 
	duzini nepoznate reci. 
*/

void pronadji_prevod(ParReci recnik[], int n, char rec[], char prevod[]){
	int i;
	
	/* Pretrazuje se recnik i trazi se zadata rec. */
	for(i=0; i<n; i++)
  {
		if(strcmp(recnik[i].sr, rec)==0)
    {
			strcpy(prevod, recnik[i].en);
			return;
		}
	}
	
	/* Ukoliko rec nije pronadjena, formira se prevod reci koji se sastoji od zvezdica. */
	for(i=0; rec[i]; i++){
		prevod[i]='*';
	}
	prevod[i]='\0';
}


int main(){
	ParReci recnik[MAX_BR_RECI];
	int n;
	char sr[MAX_DUZINA+1];
	char en[MAX_DUZINA+1];
	int i, j, k;
	char rec[MAX_DUZINA+1];
	char prevod[MAX_DUZINA+1];	
  char c;
	
	/* Ucitavaju se parovi reci sa standardnog ulaza sve do kraja ulaza. */
	i=0;
	while(scanf("%s %s", sr, en)!=EOF){
		if(i==MAX_BR_RECI)
			break;
		
		strcpy(recnik[i].sr, sr);
		strcpy(recnik[i].en, en);
		
		i++;
	}
	/* Broj parova reci se cuva u promenljivoj n. */
	n=i;
	
  printf("Unesite recenicu za prevod: \n");
	do
  {
    /* Ucitava se rec po rec date recenice i pronalazi se njen prevod. */ 
		scanf("%s", rec);
  
    pronadji_prevod(recnik, n, rec, prevod);
  	printf("%s ", prevod);

    /* Ukoliko je karakter iza reci znak za novi red, onda se prekida sa unosom, a ako nije
     * ucitava se sledeca recenica.
     */
		c = getchar();

	}while(c != '\n');

	putchar('\n');
				
	return 0;	
}
