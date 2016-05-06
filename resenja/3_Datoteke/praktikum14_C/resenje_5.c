/* Napisati program koji pronalazi maksimum brojeva zapisanih u datoteci brojevi.txt */

#include<stdio.h>

int main(){
  
  FILE* in;
  float broj, max_broj;
  
  /*Otvaramo datoteku brojevi.txt za citanje i proveravamo da li smo je uspesno otvorili*/
  in = fopen("brojevi.txt", "r");
  if(in == NULL){
	printf("Greska pri otvaranju datoteke!");
	return 0;
  }
  
  /*
   Kako bismo inicijalizovali promenljivu max_broj, 
   citamo jedan broj iz datoteke i smestamo ga u 
   ovu promenljivu. */
  fscanf(in, "%f", &max_broj);
  
  /*U petlji citamo sve ostale brojeve i poredimo ih sa trenutnim maksimumom.*/
  while(fscanf(in, "%f", &broj) != EOF){
	if(broj > max_broj)
	  max_broj = broj;
  }
  
  /*Ispisujemo rezultat*/
  printf("Najveci broj je: %.2f\n", max_broj);
  
  /*Zatvaramo datoteku brojevi.txt*/
  fclose(in);
 
  return 0;
}
