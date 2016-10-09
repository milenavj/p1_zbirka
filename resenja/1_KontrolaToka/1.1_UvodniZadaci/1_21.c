
#include <stdio.h>

int main()
{
  float a, b;
  float obim, povrsina;

  /* Ucitavamo potrebne podatke */
  printf("Unesite duzine stranica pravougaonika: ");
  scanf("%f%f", &a, &b);
  
  /* Obim */
  obim=2*(a+b);
  
  /* Povrsina */
  povrsina=a*b;
  
  /* Ispisujemo trazene vrednosti */
  printf("Obim: %.2f\n", obim);
  printf("Povrsina: %.2f\n", povrsina);
  
  /* Zavrsavamo sa programom */
  return 0;
}
