/*
a) Napisati funkciju int samoglasnik(char c) koja proverava da li je zadati karakter samoglasnik. Funkcija
treba da vrati vrednost 1 ako karakter c jeste samoglasnik, odnosno 0 ako nije.
b) Napisati funkciju int samoglasnik_na_kraju(char s[]) koja proverava da li se niska s zavrsava samoglasnikom 
(koristiti funkciju iz tacke a)).
c) Napisati program koji ucitava nisku maksimalne duzine 20 karaktera i ispisuje da li zavrsava samoglasnikom ili ne.
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX_DUZINA 20

/* Funkcija proverava da li je karakter c samoglasnik */
int samoglasnik(char c){
	
	char C;
	
	/* Konvertujemo karakter u veliko slovo kako bismo smanjili broj provera */
	C=toupper(c);
	
	/* Samoglasnici su slova a, e, i, o i u */
	if(C=='A' || C=='E' || C=='I' || C=='O' || C=='U')
		return 1;
		
	return 0;   
}

/* Funkcija koja proverava da li se niska s zavrsava samoglasnikom */
int samoglasnik_na_kraju(char s[]){
	int duzina; 
	
	/* Odredjujemo duzinu niske */
	duzina=strlen(s);
	
	/* Proveravamo da li je niska prazna */
	if(duzina==0)
		return 0;
	
	/* Ako niska nije prazna, proveravamo da li se samoglasnik nalazi na kraju */
	/* Numeracija karaktera u niski pocinje nulom pa zato proveravamo poziciju duzina -1 */
	return samoglasnik(s[duzina-1]);
}


int main(){
	char s[MAX_DUZINA+1];

	/* Ucitavamo nisku */	
	printf("Unesite nisku: ");
	scanf("%s", s);
	
	/* Proveravamo da li se zavrsava samoglasnikom i ispisujemo odgovarajucu poruku */
	if(samoglasnik_na_kraju(s))
		printf("Niska se zavrsava samoglasnikom!\n");
	else
		printf("Niska se ne zavrsava samoglasnikom!\n");
	
	return 0;
}

