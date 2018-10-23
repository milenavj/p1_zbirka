#include <stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  unsigned int n;
  int i, j;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Romb se crta crtanjem dva spojena trougla koji se nezavisno
     iscrtavaju. */

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 0; i < n; i++) {
    /* Prvo se ispisuju * koje prethode karakterima -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    /* Potom se ispisuju karakteri -. */
    for (j = 0; j < 2 * i; j++)
      printf("-");
    /* Potom se ispisuju * koje su nakon karaktera -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    printf("\n");
  }

  /* II deo: crtanje donjeg trougla. Kako je prvi red donjeg
     trougla vec ispisan (poslednji red gornjeg trougla), potrebno
     je naciniti jednu iteraciju manje. */
  for (i = n - 2; i >= 0; i--) {
    /* Prvo se ispisuju * koje prethode karakterima -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    /* Potom se ispisuju karakteri -. */
    for (j = 0; j < 2 * i; j++)
      printf("-");
    /* Potom se ispisuju * koje su nakon karaktera -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
