/*
 Napisati funkciju int heksa_broj(char s[]) koja proverava da li je niskom s zadat korektan heksadekadni broj. 
 Heksadekadni broj je korektno zadat ako pocinje prefiksom 0x ili 0X i ako sadrzi samo cifre i mala ili velika slova A, B, C, D, E i F.
 Funkcija treba da vrati vrednost 1 ako je niska korektan heksadekadni broj, odnosno 0 ako nije. 
 Napisati i program koji ucitava nisku maksimalne duzine 7 karaktera i ispisuje rezultat rada funkcije.
 */

#include<stdio.h>
#define MAX 8


/*
 Funkcija koja proverava da li je prosledjeni karakter ispravna heksadekadna cifra (broj ili slovo a,b,c,d,e,f)
 Ukoliko jeste, funkcija vraca 1, u suprotnom 0.
 */
int heksa_cifra(char c){
  /*Pretvaramo karakter c u veliko slovo*/
  c = toupper(c);
  
  /*Proveravamo da li je u pitanju cifra ili slovo A,B,C,D,E,F i ukoliko jeste, vracamo 1*/
  if(isdigit(c) || (c >= 'A' && c <= 'F'))
	return 1;
  
  /*Ukoliko nije, vracamo 0*/
  return 0;
}

/*Funkcija koja proverava da li prosledjena niska s predstavlja ispravan heksadekadni broj */
int heksa_broj(char s[]){
  int i;
  
  /*Kako heksadekadni brojevi pocinju sa 0x ili 0X, prvo proveravamo da li je taj uslov ispunjen, 
	tj. da li je s[0] jednak 0 i da li je s[1] jednak X i ako taj uslov nije ispunjen, onda 
	niska s ne predstavlja korektan heksadekadni broj */
   if(s[0] != '0' || toupper(s[1]) != 'X')
	 return 0;
   
   /*Prolazimo kroz nisku, pocev od pozicije 2 (jer su prve dve pozicije 0x) i za svaki karakter do kraja
	 niske proveravamo da li je ispravna heksadekadna cifra.
	 Ako naidjemo na bilo koji koji ne ispunjava taj uslov, onda niska s nije korektan heksadekadni broj
	 i vracamo 0. */
   for(i=2; s[i] != '\0'; i++)
	 if(!heksa_cifra(s[i]))
	   return 0;

	 /*Ako smo stigli do kraja, znaci da su svi karakteri date niske ispravne heksadekadne cifre 
	   i zato vracamo 1 */
   return 1;
}

int main() {
  char s[MAX];
  
  /*Ucitavamo nisku*/
  printf("Unesite nisku:");
  scanf("%s", s);
  
  /*Pozivamo funckiju i stampamo odgovarajucu poruku*/
  if(heksa_broj(s))
	printf("Korektan heksadekadni broj!\n");
  else
	printf("Nekorektan heksadekadni broj!\n");
  
  return 0;
}