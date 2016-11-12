#include <stdio.h>
#include <math.h>

/* Zaglavlje math.h sadrzi deklaracije velikog broja matematickih
   funkcija i konstanti. U ovom zadatku se koristi zbog konstante
   pi (M_PI)

   Ukoliko se koristi i neka funkcija matematicke biblioteke, za
   prevodjenje je neophodno ukljuciti opciju -lm npr. gcc primer.c 
   -lm */
int main()
{
  float r;
  float O;
  float P;
  printf("Unesite duzinu poluprecnika kruga:");
  scanf("%f", &r);

  O = 2 * r * M_PI;
  P = r * r * M_PI;

  printf("Obim: %.2f, povrsina: %.2f\n", O, P);

  return 0;
}
