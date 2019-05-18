#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n;
  int i, j, k;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Brojac j odredjuje koliko se karaktera (praznina i zvezdica)
     ispisuje u svakom redu. 
     U svakom drugom redu ovaj broj se povecava za 2. 
     Na pocetku je 1 (jer se ispisuje samo jedna zvezdica). */
  j = 1;

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 1; i <= n; i++) {
    /* U svakom drugom redu broj karaktera koji treba da se ispisu
       se uvecava za 2. */
    if (i % 2 == 0)
      j += 2;

    /* Ispisuje se j karaktera. */
    for (k = 0; k < j; k++)
      /* U svakom parnom redu se naiazmenicno ispisuju zvezdica i
         praznina. */
      if (i % 2 == 0) {
        if (k % 2 == 0)
          printf("*");
        else
          printf(" ");
      } else {
        /* U svakom neparnom redu se ispisuju samo zvezdice. */
        printf("*");
      }
    printf("\n");
  }

  return 0;
}
