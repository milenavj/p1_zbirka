#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja ucitava dimenziju i elemente nizova.
   Kao povratnu vrednost vraca ucitanu dimenziju. */
int ucitaj(int niz1[], int niz2[])
{
  int i, n;
  
  /* Ucitava se dimenzija niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite dimenziju nizova: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitavaju se elementi prvog niza. */
  printf("Unesite elemente niza a: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz1[i]);
  
  /* Ucitavaju se elementi drugog niza. */
  printf("Unesite elemente niza b: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz2[i]);
  
  return n;
}

/* Funkcija koja ispisuje elemente niza. */
void ispisi(int niz[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

void spoji(int a[], int b[], int n, int c[])
{
  int i;
  
  /* Niz c ima 2*n elemenata: prvih n elemenata su elementi niza b, 
     a narednih n elemenata elementi niza a. Elementi niza b se
     nalaze na pozicijama 0,1,2,...n-1, a elementi niza a na
     pozicijama n,n+1,...2*n-1. Jednim prolaskom kroz petlju na
     poziciju i u nizu c se postavlja element b[i] niza b, a na
     poziciju n+i element a[i] niza a. */
  for (i = 0; i < n; i++) {
    c[i] = b[i];
    c[n + i] = a[i];
  }  
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS], b[MAKS], c[2 * MAKS];
  int n;

  /* Ucitavaju se dimenzija i elementi nizova. */
  n = ucitaj(a, b);

  /* Formira se niz c. */
  spoji(a, b, n, c);
  
  /* Ispisuju se elementi niza c. */
  ispisi(c, 2*n);

  exit(EXIT_SUCCESS);
}
