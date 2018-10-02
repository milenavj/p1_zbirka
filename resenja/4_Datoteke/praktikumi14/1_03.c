/* Kao argumenti komandne linije se zadaju ime datoteke i ceo broj k. Napisati program koji na standardni izlaz
ispisuje sve linije zadate datoteke cija je duzina veca od k. Moze se pretpostaviti da duzina linije nece biti veca
od 80 karaktera */

#include<stdio.h>
#include<string.h>

#define MAXL 81

int main(int argc, char* argv[]){

  FILE* in;
  char linija[MAXL];
  int k;
  
  /*Proveravamo da li je program ispravno pozvan*/
  if(argc!=3){
	printf("Greska: pogresan broj argumenata!");
	return 0;
  }
  
  /*Otvaramo za citanje datoteku koja se navodi kao prvi argument komandne linije*/
  in = fopen(argv[1], "r");
  if(in == NULL){
	printf("Greska: neuspesno otvaranje datoteke!");
	return 0;
  }
  
  /*Uzimamo brojevnu vrednost drugog argumenta komandne linije*/
  k = atoi(argv[2]);
  
  /*Citamo liniju po liniju i sve linije duze od k ispisujemo na standardni izlaz*/
  while(fgets(linija, MAXL, in) != NULL){
	if(strlen(linija) > k)
	  printf("%s", linija);
  }
  printf("\n");
  
  /*Zatvaramo datoteku*/
  fclose(in);
  return 0;
}
