/* 
Napisati funkciju 
  void interpunkcija(int * br_tacaka, int * br_zareza) 
koja za tekst koji se unosi sa standardnog ulaza sve do kraja ulaza prebrojava
broj tacaka i zareza. Napisati zatim program koji testira napisanu funkciju.
*/


#include <stdio.h>

void interpunkcija(int* br_tacaka, int* br_zareza){
  
  int tacke=0, zarezi=0;
  char c;

  while((c=getchar())!=EOF){
    if(c=='.')
      tacke++;

    if(c==',')
      zarezi++;
  }

  *br_tacaka=tacke;
  *br_zareza=zarezi;

}

int main(){
  int br_tacaka, br_zareza;
  
  printf("Unesite tekst: \n");

  interpunkcija(&br_tacaka, &br_zareza);

  printf("Broj tacaka: %d\n", br_tacaka);
  printf("Broj zareza: %d\n", br_zareza);

  return 0;
}
