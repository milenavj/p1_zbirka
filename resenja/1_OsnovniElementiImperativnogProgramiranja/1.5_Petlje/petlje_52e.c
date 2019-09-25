#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  unsigned int n;
  int i, j;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%u", &n);

  /* Brojac i odredjuje koji red slike se trenutno ispisuje. */
  for (i = 0; i < n; i++) {
    /* Ispis belina koje prethode zvezdicama. */
    for (j = 0; j < n - i - 1; j++)
      printf(" ");
    /* Ispis trougla. */
    for (j = 0; j < 2 * i + 1; j++)
      if (j == 0 || j == 2 * i || (i == n - 1 && j % 2 == 0))
        printf("*");
      else
        printf(" ");
    printf("\n");
  }

  /* II deo: crtanje donjeg trougla. Kako je prvi red donjeg
     trougla vec ispisan (poslednji red gornjeg trougla), potrebno
     je naciniti jednu iteraciju manje. */
  for (i = n - 2; i >= 0; i--) {
    /* Ispis belina koje prethode zvezdicama. */
    for (j = 0; j < n - i - 1; j++)
      printf(" ");
    /* Ispis potrebnog broja zvezdica. */
    for (j = 0; j < 2 * i + 1; j++)
      if (j == 0 || j == 2 * i)
        printf("*");
      else
        printf(" ");
    printf("\n");
  }

  return 0;
}
