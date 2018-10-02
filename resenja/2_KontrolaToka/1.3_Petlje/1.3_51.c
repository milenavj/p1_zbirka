#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  for (i = 0; i < n; i++) {
    /* Kvadrat predstavlja tabelu sa n vrsta gde svaka vrsta sadrzi 
       n polja, a svako polje je isto i predstavlja karakter *. */
    for (j = 0; j < n; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
