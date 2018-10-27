#include <stdio.h>

float zbir_reciprocnih(int n)
{
  float zbir = 0;
  int i;
  
  /* Za svako i izmedju 1 i n na zbir se dodaje vrednost 1/i.
     Napomena: zbog celobrojnog deljenja mora 1.0/i. */
  for (i = 1; i <= n; i++)
    zbir += 1.0 / i;
  
  /* Kao povratna vrednost funkcije se vraca izracunati zbir. */
  return zbir;
}

int main()
{
  /* Deklaracija potrebne promenljive. */
  int n;
  
  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n:\n");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if(n <= 0)
  {
    printf("Greska: neispravan unos.\n");
    return -1;
  }
  
  /* Ispis rezultata. */
  printf("Zbir reciprocnih: %.2f\n", zbir_reciprocnih(n));

  return 0;
}
