/*
   Napisati program koji sa standardnog ulaza ucitava duzinu poluprecnika kruga
   i na standardni izlaz ispisuje njegov obim i povrsinu
*/

#include <stdio.h>
#include <math.h> /* biblioteka matematickih funkcija; za prevodjenje je neophodno ukljuciti opciju -lm
                     npr. gcc primer.c -lm */
int main()
{
  int r;
  float O;
  float P;
  printf("Unesi poluprecnik kruga:");
  scanf("%d", &r);
  
  O=2*r*M_PI; /* M_PI - konstanta pi koja se nalazi u biblioteci math.h */
  P=r*r*M_PI;
  
  printf("Obim: %f, povrsina: %f\n",O,P);
  
  return 0;
}