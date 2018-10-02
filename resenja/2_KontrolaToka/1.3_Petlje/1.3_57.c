#include <stdio.h>

int main()
{
  unsigned int n;
  int i, j, k;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Brojac j odredjuje koliko ukupno karaktera (praznina i
     karaktera *) u svakom redu se ispisuje. U svakom drugom redu
     ovaj broj se povecava za 2. Na pocetku je 1 (jer se ispisuje
     samo jedna zvezda). */
  j = 1;

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 1; i <= n; i++) {
    /* U svakom drugom redu broj ispisanih karaktera se uvecava za
       2. */
    if (i % 2 == 0)
      j += 2;
    for (k = 0; k < j; k++)
      /* U svakom drugom redu se naiazmenicno ispisuje * ili
         praznina. */
      if (i % 2 == 0) {
        if (k % 2 == 0)
          printf("*");
        else
          printf(" ");
      } else
        printf("*");

    printf("\n");
  }

  return 0;
}
