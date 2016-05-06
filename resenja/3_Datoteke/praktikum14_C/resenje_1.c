/* Napisati program koji prebrojava mala slova u datoteci test.txt */

#include<stdio.h>

int main(){
  
  FILE* in;
  int c, broj_malih=0;
  
  /*Otvaramo datoteku test.txt za citanje i proveravamo da li smo je uspesno otvorili*/
  in = fopen("test.txt", "r");
  if(in == NULL){
	printf("Greska!");
	return 0;
  }
  
  /*Citamo karakter po karakter, i ukoliko je procitani 
   *karakter  malo slovo, uvecevamo brojac*/
  while((c=fgetc(in))!=EOF){
	if(islower(c))
	  broj_malih++;
  }
  
  /*Ispisujemo rezultat*/
  printf("Broj malih slova je: %d\n", broj_malih);
  
  /*Zatvaramo datoteku*/
  fclose(in);
  
  return 0;
}
