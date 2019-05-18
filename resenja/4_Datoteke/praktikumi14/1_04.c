/* Napisati program koji prebrojava koliko se linija datoteke ulaz.txt zavrsava niskom s koja se ucitava sa stan-
dardnog ulaza. Moze se pretpostaviti da duzina linije nece biti veca od 80 karaktera, kao i da duzina niske s
ne ce biti veca od 20 karaktera */

#include<stdio.h>
#include <string.h>
#define MAXL 81
#define MAXS 21

/*Funkcija brojLinija proverava koliko linija u datoteci in se zavrsava niskom s.
 Funkcija radi tako sto cita jednu po jednu liniju iz datoteke, 
 i zatim kraj te linije poredi sa niskom s.*/
int brojLinija(FILE* in, char* s){
  
  char linija[MAXL];
  int broj_linija = 0;
  int duzina_s = strlen(s);
  int duzina_linije;
  
  while(fgets(linija, MAXL, in) != NULL){
	duzina_linije = strlen(linija);

	/* Ukoliko je znak za novi red bio indikacija kraja linije, uklanjamo ga kako bi mogli da izvrsimo 
	 *ispravno poredjenje (jer niska s nema novi red na kraju) */
	if(linija[duzina_linije-1]=='\n'){
		linija[duzina_linije-1] = '\0';
		duzina_linije--;
	}
	
	/*linija + duzina_linije ce nas odvesti na kraj tog stringa, a kada oduzmemo duzinu stringa s,
	  a kada od toga oduzmemo duzinu niske s, dobicemo bas onoliko poslednjih karaktera, koliko 
	  nam i treba. U primeru uspravna crta (|) oznacava pokazivac
		   s							ab
		   duzina_s						2
		   Linija: 						aaabbbdfsssab
										|
		   Linija + duzina linije		aaabbbdfsssab
													 |
		   Linija + duzina linije - 2	aaabbbdfsssab
												   |
		  kada kazemo strcmp(linija + duzina_linije - duzina_s, s), mi cemo u nasem primeru zaista porediti "ab" i "ab".
	 */
	if(strcmp(linija + duzina_linije - duzina_s, s) == 0)
	  broj_linija++;
  }
  return broj_linija;
}

int main() {
  
  FILE* in;
  char s[MAXS];
  
  /*Otvaramo datoteku ulaz.txt za citanje i proveravamo da li smo je uspesno otvorili*/
  in = fopen("ulaz.txt", "r");
  if(in == NULL){
	printf("Greska: neuspesno otvaranje datoteke!\n");
	return 0;
  }
  
  /*Ucitavamo nisku*/
  printf("Unesite nisku s: ");
  scanf("%s", s);
 
  /*Ispisujemo koliko linija iz datoteke se zavrsava sa niskom s*/
  printf("Broj linija: %d\n", brojLinija(in, s));
  
  /*Zatvaramo datoteku*/
  fclose(in);
 
  return 0;
}
