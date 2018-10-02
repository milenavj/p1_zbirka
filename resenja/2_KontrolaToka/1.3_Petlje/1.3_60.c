#include <stdio.h>

int main()
{
  unsigned int n, i, j;

  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Slika se sastoji iz dva dela, trougla i kvadrata i svaki deo
     se nezavisno iscrtava. */

  /* Prvo se iscrtava krov, odnosno trougao. */
  for (i = 0; i < n - 1; i++) {
    /* Prvo se ispisuju beline koje prethode karakterima *. */
    for (j = 0; j < n - i - 1; j++)
      printf(" ");
    for (j = 0; j < 2 * i + 1; j++)
      if (j == 0 || j == 2 * i)
        printf("*");
      else
        printf(" ");
    printf("\n");
  }

  /* Potom se iscrtava kvadat. Da bi iscrtavanje bilo lakse
     istovremeno se ispisuju dva karaktera. */
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++)
      /* Provera da li je ivica. */
      if (j == 0 || j == n - 1 || i == 0 || i == n - 1)
        printf("* ");
      else
        printf("  ");
    printf("\n");
  }

  return 0;
}
