#include <stdio.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  double razlomak;

  /* Ucitava se vrednost broja n.  */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */  
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Razlomak se izracunava "od nazad", odnosno, krece se od
     najnizeg razlomka 1/n i od njega se nadalje formira sledeci,
     "visi" razlomak itd. Zavrsava se kada se stigne do koraka 0 +
     1/R. */
  razlomak = n;
  for (i = n - 1; i >= 0; i--)
    razlomak = i + 1 / razlomak;

  /* Ispis rezultata. */
  printf("R = %lf\n", razlomak);

  return 0;
}
