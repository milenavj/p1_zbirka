#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja kvadrira elemente niza koji se nalaze na parnim
   pozicijama. */
void kvadriranje(float a[], int n)
{
  int i;
  /* Obilaze se elementi na parnim pozicijama i kvadriraju se: 
     a[i] postaje a[i]*a[i]. */
  for (i = 0; i < n; i += 2)
    a[i] *= a[i];
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, i;
  float a[MAKS];

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:");
  for (i = 0; i < n; i++)
    scanf("%f", &a[i]);

  /* Poziva se funkcija. */
  kvadriranje(a, n);

  /* Ispisuju se elementi novodobijenog niza. */
  for (i = 0; i < n; i++)
    printf("%g ", a[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
