#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, broj;
  int suma = 0;
  int i;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Ucitava se n brojeva i izracunava se trazena suma. */
  printf("Unesite brojeve: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &broj);

    if (broj % 5 == 0 && broj % 7 != 0)
      suma += broj;
  }

  /* Ispis rezultata. */
  printf("Suma je %d.\n", suma);

  return 0;
}
