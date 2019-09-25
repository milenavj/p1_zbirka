#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n;
  int i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Romb se crta crtanjem dva spojena trougla koji se nezavisno
     iscrtavaju. */

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 0; i < n; i++) {
    /* Ispis zvezdica koje prethode karakterima -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    /* Ispis karaktera -. */
    for (j = 0; j < 2 * i; j++)
      printf("-");
    /* Ispis zvezdica koje su nakon karaktera -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    printf("\n");
  }

  /* II deo: crtanje donjeg trougla. Kako je prvi red donjeg
     trougla vec ispisan (poslednji red gornjeg trougla), potrebno
     je naciniti jednu iteraciju manje. */
  for (i = n - 2; i >= 0; i--) {
    /* Ispis zvezdica koje prethode karakterima -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    /* Ispis karaktera -. */
    for (j = 0; j < 2 * i; j++)
      printf("-");
    /* Ispis zvezdica koje su nakon karaktera -. */
    for (j = 0; j < n - i; j++)
      printf("*");
    printf("\n");
  }

  return 0;
}
