#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int i, n;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: pogresan unos broja n.\n");
    return -1;
  }
  
  /* Inicijalizacija brojaca. */
  i = 0;
  
  /* Trazena poruka se ispisuje n puta. */
  while (i < n) {
    printf("Mi volimo da programiramo.\n");
    i++;
  }

  return 0;
}
