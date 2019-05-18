/* Napisati program koji prepisuje svaki treci karakter datoteke ulaz:txt u datoteku izlaz.txt */

#include<stdio.h>

int main() {
  
  FILE *in, *out;
  int c;
  int rbr_karaktera;

  
  /*Otvaramo datoteku ulaz.txt za citanje i proveravamo da li smo je uspesno otvorili*/
  in = fopen("ulaz.txt", "r");
  if(in == NULL){
	printf("Greska!");
	return 0;
  }
  
  /*Otvaramo datoteku izlaz.txt za pisanje i proveravamo dali smo je uspesno otvorili*/
  out = fopen("izlaz.txt", "w");
  if(out == NULL){
	printf("Greska!");
	return 0;
  }
  
  /* Inicijalizujemo redni broj karaktera koji se cita */
  rbr_karaktera=0; 
   
  /* Citamo karakter po karakter iz datoteke sve dok ne stignemo do kraja datoteke */
  while((c=fgetc(in)) != EOF){

  	/* Ukoliko je procitani karakter na poziciji koja je deljiva sa 3 prepisujemo ga */
  	if(rbr_karaktera%3==0)
		fputc(c, out);
		
	/* Uvecavamo redni broj karaktera */
	rbr_karaktera++;
  }
  
  /*Zatvaramo obe datoteke koje smo otvorili*/
  fclose(out);
  fclose(in);
  return 0;
}
