/* Napisati program koji linije koje se ucitavaju sa standardnog ulaza sve do kraja ulaza prepisuje u datoteku
izlaz:txt i to, ako je prilikom pokretanja zadata opcija -v ili -V samo one linije koje pocinju velikim slovom,
ako je zadata opcija -m ili -M samo one linije koje pocinju malim slovom, a ako je opcija izostavljena sve linije.
Pretpostaviti da linije nece biti duze od 80 karaktera.
*/

#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXL 81

int main(int argc, char* argv[]){
  
  char linija[MAXL];
  FILE* izlaz;
  
  /*Indikatori koji oznacavaju koja opcija je navedena kao argument komandne linije
	vind - ispisuju se recenice koje pocinju velikim slovom
	mind - ispisuju se recenice koje pocinju malim slovom
   */
  int vind=0, mind = 0;
  
  /*Proveravamo da li je program ispravno pozvan*/
  if(argc > 2){
	printf("Greska pri pozivanju programa!\n");
	return 0;
  }
  
  /*Ako opcije nisu zadate, onda treba da se ispisuju sve recenice, pa postavljamo oba indikatora na 1*/
  if(argc == 1){
	vind = mind = 1;
  }else{
	
	/*Proveravamo da li je postavljena neka od opcija -v,-V,-m, -M
	 Ako jeste, postavljamo odgovarajuci indikator
	 Ako nije, onda ispisujemo poruku o gresci*/
	if(strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "-V") == 0)
	  vind = 1;
	else if(strcmp(argv[1], "-m") == 0 || strcmp(argv[1], "-M") == 0)
	  mind = 1;
	else{
	  printf("Greska pri zadavanju opcije!\n");
	  return 0;
	}
  }
  
  
  /*Otvaramo datoteku izlaz.txt za pisanje i proveravamo da li smo je uspesno otvorili*/
  izlaz = fopen("izlaz.txt", "w");
  if(izlaz == NULL){
	printf("Greska pri otvaranju datoteke!\n");
	return 0;
  }
	
	/*Citamo liniju po liniju sa standardnog ulaza i ispisujemo je u datoteku.
	 Liniju ispisujemo ukoliko je ispunjen neki od dva uslova:
	  1. Izabrana je opcija za ispis malih slova i linija pocinje malim slovom
	  2. Izabrana je opcija za velika slova i linija pocinje velikim slovom
	 NAPOMENA: Kada dodje do kraja ulaza, funkcija fgets vraca NULL
	 */
  while(fgets(linija, MAXL, stdin) != NULL){
	if( mind && islower(linija[0]) || vind && isupper(linija[0]) || mind && vind)
	  fputs(linija, izlaz);  
  }
  
  /*Zatvaramo datoteku izlaz.txt*/
  fclose(izlaz);
  
  return 0;
}
