/*
 Napisati funkciju int podniska(char s[], char t[]) koja proverava da li je niska t podniska niske s. 
 Napisati i program koji ucitava dve niske maksimalne duzine 10 karaktera i testira rad napisane funkcije.
 
 Napomena: u biblioteci string.h postoji funkcija strstr 
 char* strstr(const char* s, const char* t) 
 koja vraca adresu pocetka prvog pojavljivanja niske t u niski s ili NULL ako se niska t ne javlja 
 u niski s.
 */

#include<stdio.h>
#define MAX 11

/*Funkcija koja proverava da li je t podniska od s*/
int podniska(char s[], char t[]){
  int i, j, k;

  /*Spoljna petlja ide redom po niski s*/
  for(i=0; s[i] != '\0'; i++){
	
	/*Unutrasnja petlja ide redom po niski t*/
	/*Promenljiva k pamti vrednost i, sluzi za poredjenje s[k] i t[j] i 
	 *zatim se vrsi pomeranje i po niski s i po niski t (k++, j++) */
	/*Cim naidjemo na situaciju da se karakteri ne poklapaju, izlazimo iz  unutrasnje petlje*/
	for(j=0, k = i; t[j] != '\0'; j++, k++){
	  if(s[k] != t[j])
		break;
	}
	
	/*Ako smo prosli celu unutrasnju petlju (do kraja niske t), to znaci da su se svi karakteri iz t poklopili
	 sa karakterima iz s i onda vracamo 1*/
	if(t[j] == '\0')
	  return 1;
  }
  
  /*Na kraju vracamo 0*/
  return 0;
}


int main() {
  char s[MAX], t[MAX];
  
  /*Ucitavamo prvu nisku*/
  printf("Unesite nisku s: ");
  scanf("%s", s);
  
  /*Ucitavamo drugu nisku*/
  printf("Unesite nisku t: ");
  scanf("%s", t);
  
  /*Pozivamo funkciju i ispisujemo odgovarajucu poruku*/
  if(podniska(s,t))
	printf("t je podniska niske s!\n");
  else
	printf("t nije podniska niske s!\n");
  
  return 0;
}

