#include <stdio.h>
#include <stdlib.h>

int main()
{

  int n;
  int x, x_kopija, br_cifara;
  int max_br_cifara, broj;
  int i;

  printf("Unesite broj n: ");
  scanf("%d", &n);

  if (n < 0) {
    printf("Neispravan unos.\n");
    return -1;
  }

  if (n == 0) {
    printf("Nisu uneseni brojevi.\n");
    return 0;
  }

  /* Maksimalan broj cifara se postavlja na 0, svaki broj ima vise
     od 0 cifara pa je ova vrednost neutralna. */
  max_br_cifara = 0;

  printf("Unesite n brojeva: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &x);

    /* Odredjivanje broja cifara unetog broja x. */
    x_kopija = abs(x);
    br_cifara = 0;
    while (x_kopija != 0) {
      x_kopija = x_kopija / 10;
      br_cifara++;
    }

    /* Ako je broj cifara unetog broja veci od maksimalnog */
    if (br_cifara > max_br_cifara) {
      /* Cuvamo ga */
      max_br_cifara = br_cifara;
      /* I zbog ispisa rezultata, cuvamo i originalni broj */
      /* Zbog ovoga smo morali i da racunamo broj cifara nad
         kopijom broja x kako ne bismo promenili njegovu vrednost */
      broj = x;
    }
  }

  printf("Najvise cifara ima broj %d\n", broj);

  return 0;
}
