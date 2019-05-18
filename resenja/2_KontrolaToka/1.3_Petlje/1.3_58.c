#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n, m;
  int i, j;

  /* Ucitavanje dimenzije slike. */
  printf("Unesite brojeve n i m: ");
  scanf("%u%u", &n, &m);

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. Ukupno 
     ima m redova. */
  for (i = 1; i <= m; i++) {
    /* Brojac j oznacava koja kolona se trenutno ispisuje. Za
       svaki kvadrat se racuna duzina bez poslednje ivice. Kvadrat
       je sastavljen od (m-1) zvezdice i (m-1) praznine (praznine
       se nalaze izmedju zvezdica). Znaci ukupna duzina je 2*(m-1)
       karakter, a kako ima n kvadrata plus jedna kolona za
       najdesniju ivicu, duzina je n*2*(m-1) + 1. */
    for (j = 0; j <= n * 2 * (m - 1); j++)
      /* Provera da li se ispisuje prvi ili poslednji red. */
      if (i == 1 || i == m)
        /* Naizmenican ispis zvezdice i praznine. */
        if (j % 2 == 0)
          printf("*");
        else
          printf(" ");
      else
        /* Na ivicama kvardata se iscrtavaju zvezdice, a na ostalim
           mestima beline. */
      if (j % (2 * (m - 1)) == 0)
        printf("*");
      else
        printf(" ");

    printf("\n");
  }

  return 0;
}
