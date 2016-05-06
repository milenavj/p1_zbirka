/* Napisati program koji omogucava korisniku da unese ceo broj, a zatim
ispisuje njegov kvadrat i kub */

#include <stdio.h>

int main(){
  int n; 
  
  /* Ucitavamo broj */
  printf("Unesite ceo broj: ");
  scanf("%d", &n);
  
  /* Ispisujemo trazene vrednosti */
  printf("Kvadrat: %d\n", n*n);
  printf("Kub: %d\n", n*n*n);
 
  /* Zavrsavamo sa programom */
  return 0;
}