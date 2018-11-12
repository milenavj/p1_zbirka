#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja ucitava dimenziju i elemente niza.
   Kao povratnu vrednost vraca ucitanu dimenziju. */
int ucitaj(float a[])
{
  int i, n;
  
  /* Ucitava se dimenzija niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%f", &a[i]);
  
  return n;
}

/* Funckija racuna zbir prvih k pozitivnih elemenata niza. */
float zbir_pozitivnih(float a[], int n, int k)
{
  int i;
  float zbir = 0;

  /* Obilazi se element po element niza. Postupak se zavrsava
     ukoliko se dodje do kraja niza ili ukoliko se sabere k
     pozitivnih elemenata. */
  for (i = 0; i < n && k > 0; i++) {
    if (a[i] >= 0) {
      zbir += a[i];
      /* Umanjuje se brojac pozitivnih elemenata. */
      k--;
    }
  }

  return zbir;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, k;
  float a[MAKS];

  /* Ucitavaju se dimenzija i elementi niza. */
  n = ucitaj(a);

  /* Ucitava se broj k i vrsi se provera ispravnosti ulaza. */
  printf("Unesite vrednost k: ");
  scanf("%d", &k);
  if (k < 0 || k > n) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ispis rezultata. */
  printf("Zbir je: %.2f\n", zbir_pozitivnih(a, n, k));

  exit(EXIT_SUCCESS);
}
