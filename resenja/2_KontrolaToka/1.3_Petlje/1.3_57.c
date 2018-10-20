#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n;
  int i, j, k;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Brojac j odredjuje koliko ukupno karaktera (praznina i
     karaktera *) u svakom redu se ispisuje. U svakom drugom redu
     ovaj broj se povecava za 2. Na pocetku je 1 (jer se ispisuje
     samo jedna zvezda). */
  j = 1;

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 1; i <= n; i++) {
    /* U svakom drugom redu broj karaktera koji treba da se
       ispisu se uvecava za 2. */
    if (i % 2 == 0)
      j += 2;
    
    /* Ispisuje se j karaktera. */
    for (k = 0; k < j; k++)
      /* U svakom parnom redu se naiazmenicno 
         ispisuju * i praznina. */
      if (i % 2 == 0) {
        if (k % 2 == 0)
          printf("*");
        else
          printf(" ");
      } 
      else
      {
        /*U svakom neparnom redu se ispisuju samo *. */
        printf("*");
      }
    printf("\n");
  }

  return 0;
}
