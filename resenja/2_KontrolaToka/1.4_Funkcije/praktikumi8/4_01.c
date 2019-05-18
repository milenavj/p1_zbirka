#include <stdio.h>

/*	Funkcija koja racuna minimum tri cela broja. */
int min(int x, int y, int z){
  int min;
  
  /* Pretpostvka je da je minimum broj x. Potom se minimum poredi sa druga dva broja i ukoliko pretpostavka nije dobra, vrednost minimuma se menja. */
  min=x;
  
  if(min>y) 
  	min=y;
  	
  if(min>z)
  	min=z;
  	
  return min;
}

int main() {
  int x,y,z;
	
  /* Unose se tri broja. */
  printf("Unesite brojeve: ");
  scanf("%d%d%d", &x, &y, &z);
  
  /* Poziv funkcije i ispis rezultata. */
  printf("Minimum je: %d\n", min(x,y,z));
	
  return 0;
}

