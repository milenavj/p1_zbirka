#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a, b;

  /* Ucitavaju se vrednosti a i b. */
  printf("Unesite vrednosti a i b: ");
  scanf("%d%d", &a, &b);

  /* U promenljivu a se smesta suma a+b. */
  a = a + b;
  
  /* U promenljivu b se smesta izraz a - 2*b, cija je vrednost (nakon promene promenljive a) jednaka  a + b - 2*b = a - b. */
  b = a - 2*b; 

  /* Ispis rezultata. */
  printf("Nove vrednosti su: a=%d, b=%d\n", a, b);

  return 0;
}
