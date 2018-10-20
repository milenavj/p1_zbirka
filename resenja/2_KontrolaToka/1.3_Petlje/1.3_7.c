#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i, znak;
  float x, rezultat;

  /* Ucitavaju se vrednosti brojeva x i n. */
  printf("Unesite redom brojeve x i n: ");
  scanf("%f %d", &x, &n);
  
  /* Pamti se znak stepena i uzima se apsolutna vrednost stepena. */
  znak = 1;
  if(n < 0){
    znak = -1;
    n = abs(n);
  }
  /* Inicijalizacija rezultata. */
  rezultat = 1;

  /* Racuna se vrednost x^n. */
  for (i=0; i<n; i++)
    rezultat = rezultat * x;

  /* Ako je stepen bio negativan, rezultat je 1/x^n. */
  if (znak == -1)
    printf("Rezultat: %.3f\n", 1 / rezultat);
  else
    printf("Rezultat: %.3f\n", rezultat);

  return 0;
}
