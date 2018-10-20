#include<stdio.h>

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, x, i;
  int suma_pozitivnih;
  int suma_negativnih;

  /* Ucitava se vrednost broja n. */
  printf("Unesite broj n:");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Inicijalizacija suma. */
  suma_pozitivnih = 0;
  suma_negativnih = 0;

  /* Ucitavanje brojeva i izracunavanje suma. */
  printf("Unesite %d brojeva: ", n);
  i = 0;
  while (i < n) {
    /* Ucitava se jedan broj. */
    scanf("%d", &x);

    /* Dodaje se na odgovarajucu sumu. */
    if (x < 0)
      suma_negativnih += x;
    else
      suma_pozitivnih += x;

    /* Uvecava se brojac. */
    i++;
  }

  /* Ispis rezultata. */
  printf("Suma pozitivnih: %d\n", suma_pozitivnih);
  printf("Suma negativnih: %d\n", suma_negativnih);
  
  return 0;
}
