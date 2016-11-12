#include <stdio.h>
#include <math.h>

int main()
{

  int n;
  int x, x_kopija;
  int broj;
  int vodeca_cifra, max_vodeca_cifra;
  int i;

  /* Citamo vrednost sa ulaza */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Postavljamo maksimalnu vodecu cifru na 0 - cifre broja su vece 
     ili jednake od 0 pa je ova vrednost neutralna */
  max_vodeca_cifra = 0;

  /* Ucitavamo broj po broj */
  printf("Unesite n brojeva: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &x);

    /* Odredjujemo vodecu cifru broja */
    x_kopija = abs(x);
    while (x_kopija > 10) {
      x_kopija = x_kopija / 10;
    }
    vodeca_cifra = x_kopija;

    /* Ako je izdvojena cifra veca od maksimalne vodece cifre */
    if (vodeca_cifra > max_vodeca_cifra) {
      /* Cuvamo je */
      max_vodeca_cifra = vodeca_cifra;
      /* I zbog ispisa, cuvamo i broj u kojem se ona pojavljuje */
      /* Zbog ovoga smo morali i da racunamo vodecu cifru nad
         kopijom broja x kako ne bismo promenili njegovu vrednost */
      broj = x;
    }
  }

  /* Ispisujemo rezultat */
  printf("%d\n", broj);

  return 0;

}
