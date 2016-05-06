/*
	Definisati strukturu ParReci koja sadrzi rec na srpskom jeziku i odgovarajuci prevod na engleski jezik. Zatim
	sa standardnog ulaza sve do kraja ulaza ucitavati parove reci i, posebno, za recenicu koja se zadaje sa ulaza
	ispisati prevod - ako je rec u recenici nepoznata umesto nje ispisati odgovarajuci broj zvezdica. Reci nece biti
	duze od 50 karaktera, a ukupan broj reci nece biti veci od 100. Napomena: probati sa testiranjem zadataka
	pomocu preusmeravanja.
*/

#include <stdio.h>
#include <string.h>
#define MAX_DUZINA 20
#define MAX_BR_RECI 100
#define MAX_DUZINA_RECENICE 100

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
	
	/* Pretrazujemo recnik i trazimo zadatu rec */
	for(i=0; i<n; i++){
	
		/* Ukoliko se rec nalazi u recniku */
		if(strcmp(recnik[i].sr, rec)==0){
			/* Ocitavamo njen prevod */
			strcpy(prevod, recnik[i].en);
			/* I obustavljamo pretragu */
			return;
		}
	}
	
	/* Ukoliko rec nije pronadjena, formiramo prevod reci koji se sastoji od zvezdica */
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
	char recenica[MAX_DUZINA_RECENICE+1];
	char rec[MAX_DUZINA+1];
	char prevod[MAX_DUZINA+1];	
	int citamo_rec;
	char* novi_red;
	
	/* Ucitavamo parove reci sa standardnog ulaza sve do kraja ulaza*/
	i=0;
	while(scanf("%s %s", sr, en)!=EOF){
		if(i==MAX_BR_RECI)
			break;
		
		strcpy(recnik[i].sr, sr);
		strcpy(recnik[i].en, en);
		
		i++;
	}
	/* Broj parova reci cuvamo u promenljivoj n */
	n=i;
	
	/* Ucitavamo recenicu - nisku karaktera sve do pojave znaka za novi red */
	printf("Unesite recenicu za prevod:\n");
	fgets(recenica, MAX_DUZINA_RECENICE, stdin);
	
	/* Ako postoji, zamenjujemo znak za novi red terminirajucom nulom */
	novi_red=strchr(recenica, '\n');
	if(novi_red!=NULL)
		*novi_red='\0';
	

	/* Izdvajamo rec po rec unesene recenice */
	/* j oznacava tekuci karakter recenice koji se obradjuje */
	j=0; 
	/* citamo_rec sa mogucim vrednostima 1 i 0 ce biti indikator koji pokazuje da li citamo rec ili ne */
	citamo_rec=0;
	
	while(1){
		/* Proveravamo da li smo stigli do kraja recenice */
		if(recenica[j]=='\0')
			break;
		
		/* Ukoliko smo procitali karakter koji je sastavni deo reci (nije belina) */
		if(recenica[j]!=' ' && recenica[j]!='\n' && recenica[j]!='\t'){
				/* Smestamo ga u rec */
				if(citamo_rec==0){
					citamo_rec=1;						
					k=0;
				}
				rec[k]=recenica[j];
				k++;
		}
		else{
			/* Inace, procitali smo karakter koji ne treba ukljuciti u rec */
			/* Ako smo pre toga citali rec */
			if(citamo_rec==1){
				/* Prekidamo citanje */
				citamo_rec=0;
				rec[k]='\0';
				
				/* I trazimo i ispisujemo odgovarajuci prevod reci */
				pronadji_prevod(recnik, n, rec, prevod);
				printf("%s ", prevod);
			}
		}

		/* Prelazimo na sledeci karakter recenice */		
		j++;
	}
		
	/* Za slucaj da nije obradjena, obradjujemo poslednju rec i ispisujemo njen prevod */
	if(citamo_rec){
		rec[k]='\0';
		pronadji_prevod(recnik, n, rec, prevod);
		printf("%s\n", prevod);
	}
	

	return 0;	

}
