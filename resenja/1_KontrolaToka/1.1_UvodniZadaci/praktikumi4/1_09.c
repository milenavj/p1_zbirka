
#include <stdio.h>
#include <math.h>

int main()
{
  int x, c, p;
  int levo, desno;
  int novo_x;

  /* Ucitavamo potrebne vrednosti */
  printf("Unesite redom x, c i p: ");
  scanf("%d%d%d", &x, &c, &p);
  
  /* Odredjujemo deo broja koji se nalazi desno od pozicije p */
  desno=x%(int)pow(10, p-1);
  
  /* Odredjujemo deo broja koji se nalazi levo od pozicije p */
  levo=x/(int)pow(10, p-1);
  
  /* Odredjujemo novi broj */
  novo_x=levo*(int)pow(10, p) +c*(int)pow(10, p-1) + desno;
 
  /* Ispisujemo dobijenu vrednost */
  printf("Rezultat je: %d\n", novo_x);
  
  /* Zavrsavamo sa programom */
  return 0;

}
