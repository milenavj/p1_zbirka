#include <stdio.h>
#include <math.h> 

/* Biblioteka math.h sadrzi veliki broj matematickih 
   funkcija i konstanti. U ovom zadatku je koristimo 
   zbog konstante pi (M_PI)
   
   Za prevodjenje je neophodno ukljuciti opciju -lm
   npr. gcc primer.c -lm 
*/
int main()
{
  float r;
  float O;
  float P;
  printf("Unesite duzinu poluprecnika kruga:");
  scanf("%f", &r);
  
  O=2*r*M_PI;
  P=r*r*M_PI;
  
  printf("Obim: %.2f, povrsina: %.2f\n",O,P);
  
  return 0;
}