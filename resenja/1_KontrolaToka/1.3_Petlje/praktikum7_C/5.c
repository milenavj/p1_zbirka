/* Sa standardnog ulaza se unosi ceo broj n, a zatim i n karaktera. Napisati program koji proverava da li se od
unetih karaktera moze napisati rec Zima. */

#include <stdio.h>
#include <math.h>

int main(){

	int n;
	int broj_Z, broj_i, broj_m, broj_a;	 
	char novi_red, c;
	int i;
	
	broj_Z=0; 
	broj_i=0; 
	broj_m=0;
	broj_a=0;
	
	
	/* Ucitavamo broj karaktera */
	printf("Unesite broj: ");
	scanf("%d", &n);

	/* Ucitavamo karakter po karakter */	
	for(i=0; i<n; i++){
		printf("Unestite %d. karakter: ", i+1);		
		/* 
			Prvo citamo znak za novi red koji je ostao neprocitan nakon pritiska Enter tastera 
			posle prethodnog unosa, pa tek onda citamo karakter koji treba obradjivati 
		*/
		scanf("%c%c", &novi_red, &c);
		
		/* Analiziramo karakter */
		switch(c){
			case 'Z': 
				broj_Z++;
				break;
			case 'i':
				broj_i++;
				break;
			case 'm':
				broj_m++;
				break;
			case 'a':
				broj_a++;
				break;				
		}
	}
	
	/* Ako imamo barem jedno veliko slovo z i barem po jedno malo slovo i, m i a */	
	if(broj_Z && broj_i && broj_m && broj_a){
		/* Zakljucujemo da se rec moze napisati */
		printf("Moze se napisati rec Zima.\n");
	}		
	else{
		/* Inace, obavestavamo korisnika da je to nemoguce */
		printf("Ne moze se napisati rec Zima.\n");			
	}
		
	return 0;
}

