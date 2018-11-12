#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja ucitava dimenziju i elemente niza.
   Kao povratnu vrednost vraca ucitanu dimenziju. */
int ucitaj(int a[])
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
    scanf("%d", &a[i]);
  
  return n;
}

/* Funkcija prebrojavanje vraca broj elemenata niza koji su manji
   od poslednjeg elementa. */
int prebrojavanje(int a[], int n)
{
  int i;
  int broj_manjih = 0;

  /* Prebrojavaju se elementi niza za koje vazi da su manji od 
     poslednjeg elementa (a[n-1]). Petlja ide od prvog do
     predposlednjeg elementa. */
  for (i = 0; i < n - 1; i++) 
  {
    if (a[i] < a[n - 1])
      broj_manjih++;
  }

  return broj_manjih;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n;

  /* Ucitavaju se dimenzija i elementi niza. */
  n = ucitaj(a);

  /* Ispis rezultata. */
  printf("%d\n", prebrojavanje(a, n));

  exit(EXIT_SUCCESS);
}
