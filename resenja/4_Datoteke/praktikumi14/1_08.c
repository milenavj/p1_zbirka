/* Napisati program koji za rec s maksimalne duzine 20 karaktera koja se zadaje sa standardnog ulaza u datoteku
rotacije.txt upisuje sve rotacije reci s */

#include<stdio.h>
#include<string.h>

#define MAXS 21

/*Funkcija rotira nisku za jedno mesto u desno.
 Duzina niske n nije obavezan argument. Mogli smo 
 i da je racunamo u okviru funkcije, ali kako ce sve niske
 sa kojima radimo biti iste duzine, efikasnije je da jednom
 izracunamo tu duzinu u glavnom programu, 
 pa da je prosledjujemo kao argument.*/
void rotiraj_za_1(char* s, int n){
  int i;
  char c = s[0];
  for(i=0; i<n-1; i++){
	s[i] = s[i+1];
  }
  s[n-1] = c;
}

int main(){
  
  char s[MAXS];
  int n, i;
  FILE * izlaz;
  
  /*Otvaramo datoteku rotacije.txt za pisanje i proveravamo da li smo je uspesno otvorili*/
  izlaz = fopen("rotacije.txt", "w");
  if(izlaz == NULL){
	printf("Greska pri otvaranju fajla!");
	return 0;
  }

  /*Sa standardnog ulaza ucitavamo rec koju treba da rotiramo*/
  scanf("%s", s);
  
  /*Racunamo njenu duzinu*/
  n = strlen(s);
  
  /*U petlji, ispisujemo tu rec u datoteku, pa je rotiramo za jedno mesto u desno.*/
  for(i=0; i<n; i++){
	fprintf(izlaz, "%s\n", s);
	rotiraj_za_1(s,n);
  }
  
  /*Zatvaramo datoteku rotacije.txt*/
  fclose(izlaz);
  
  return 0;
  
}
