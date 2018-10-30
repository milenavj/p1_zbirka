#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS 100

/* Funkcija prebrojava cifre u datom nizu karaktera. */
int cifre(char a[], int n)
{
  int i, broj_cifara = 0;

  for (i = 0; i < n; i++) {
    if (isdigit(a[i]))
      broj_cifara++;
  }

  return broj_cifara;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  char a[MAKS];
  int n, i;

  /* Ucitava se broj elemenata niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj elemenata niza:");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:");
  for (i = 0; i < n; i++) {
    /* Preskace se prethodno uneti znak za novi red. */
    getchar();

    /* Ucitava se karakter i smesta se u niz. */
    scanf("%c", &a[i]);
  }

  /* Ispis rezultata. */
  printf("Broj cifara je: %d\n", cifre(a, n));

  exit(EXIT_SUCCESS);
}
