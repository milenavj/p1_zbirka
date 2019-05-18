/* Napisati funkciju int heksa_broj(char s[]) koja izracunava dekadnu vrednost heksadekadnog broja zadatog niskom s. 
 * Napisati i program koji ucitava nisku maksimalne duzine 7 karaktera i ispisuje rezultat rada funkcije.
 * Pretpostaviti da je uneta niska korektan heksadekadni broj. */

#include<stdio.h>
#include<string.h>

#define MAX 8

/*Funkcija koja racuna dekadnu vrednost heksadekadnog broja*/
int heksa_broj(char s[]){
  int i,k;
  char c;
  
  /*Racunamo duzinu niske koja predstavlja heksadekadni broj*/
  int n = strlen(s);
  
  /*Inicijalizujemo vrednost v na 0*/
  int v = 0;
  
  /*Prolazimo petljom kroz nisku, krenuvsi sa desne strane 
	npr: 1a8e = e*1 + 8*16 + a*256 + 1*4096
	Promenljiva k ce nam biti mnozilac i ona uzima vrednosti 1, 16, 256, 4096, ... 
	Promenljiva c ce nam cuvati trenutnu heksadekadnu cifru (u nasem primeru e, 8, a, 1)
	U svakom koraku treba na ispravan nacin da pomnozimo c i k
	*/
  for(i=n-1, k=1; i>=2; i--, k*=16)
  {
	/*U c smestamo trenutnu heksadekadnu cifru.
	 Pozivamo funkciju toupper da bi obezbedili da radimo samo sa velikim slovima.
	 Ako je s[i] cifra, funkcija toupper je nece promeniti.
	 */
	c = toupper(s[i]);
	
	if(isdigit(c)){
	  /*Ako je c cifra, onda samu vrednost te cifre dobijamo sa c-'0'
	   NAPOMENA: Nije ispravno napisati c*k jer je c karakter!
	   */
	  v += (c-'0')*k;
	}else{
	  /*Ako je c slovo izmedju A i F, mi treba da dobijemo odgovarajucu vrednost izmedju 10 i 15.
	   Ova vrednost se dobija sa 10 + c - 'A'. npr. za A ce biti 10 + 'A' - 'A' = 10, za B: 10 + 'B' - 'A' = 11, ...*/
	  v += (c - 'A' + 10)*k;
	}
  }

	/*Na kraju vracamo izracunatu vrednost */
   return v;
}

int main() {
  char s[MAX];

  /*Ucitavamo nisku*/
  printf("Unesite nisku:");
  scanf("%s", s);
  
  /*Ispisujemo rezultat*/
  printf("%d\n", heksa_broj(s));
  
  return 0;
}