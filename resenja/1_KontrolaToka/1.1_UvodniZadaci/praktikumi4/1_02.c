/* Napisati program koji za unete stranice pravougaonika ispisuje njegov obim i
povrsinu */

#include <stdio.h>

int main(){
  int a, b;
  int obim, povrsina;

  /* Ucitavamo potrebne podatke */
  printf("Unesite duzine stranica pravougaonika: ");
  scanf("%d %d", &a, &b);
  
  /* Obim */
  obim=2*(a+b);
  
  /* Povrsina */
  povrsina=a*b;
  
  /* Ispisujemo trazene vrednosti */
  printf("Obim: %d\n", obim);
  printf("Povrsina: %d\n", povrsina);
  
  /* Zavrsavamo sa programom */
  return 0;
}