#include <stdio.h>

/*
	Funkcija koja racuna minimum tri cela broja
*/
int min(int x, int y, int z){
  int min;
  
  min=x;
  
  if(min>y) 
  	min=y;
  	
  if(min>z)
  	min=z;
  	
  return min;
}

int main(){
  int x,y,z;
	
  /* Ucitavamo brojeve */
  printf("Unesite brojeve: ");
  scanf("%d%d%d", &x, &y, &z);
  
  /* Pozivamo funkciju i ispisujemo rezultat */
  printf("Minimum je: %d\n", min(x,y,z));
	
  return 0;
}

