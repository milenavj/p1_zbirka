#include <stdio.h>

int main () {
  /* Deklaracije potrebnih promenljivih. */
  int i , n;
  float suma, x, clan;
  
  /* Ucitavanje i provera ispravnosti ulaza. */
  printf("Unesite redom brojeve x i n: ");
  scanf("%f%d", &x, &n);

  if (n <= 0) {
      printf("Greska: neispravan unos.\n");
      return -1;
  }

  /* Inicijalizacije. */
  suma = 1;
  clan = 1;
  i = 2;

  /* Racuna se trazena suma. */
  while (i <= 2 * n) {
      /* Svaki clan suma se od prethodnog clana razlikuje za
         x^2/(i*(i-1)). */
      clan = clan * x * x / (i * (i - 1));
      clan *= -1;
      
      suma += clan;
      i += 2;
  }

  /* Ispis rezultata. */
  printf("S=%f\n", suma);

  return 0;
  }