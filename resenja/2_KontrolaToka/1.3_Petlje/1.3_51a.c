#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n, i, j;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Kvadrat predstavlja tabelu sa n vrsta gde svaka vrsta sadrzi
     n polja, a svako polje je isto i predstavlja karakter *. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
