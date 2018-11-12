#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja ucitava dimenziju i elemente niza.
   Kao povratnu vrednost vraca ucitanu dimenziju. */
int ucitaj(int niz[])
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
    scanf("%d", &niz[i]);
  
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

/* Funkcija koja brise sve elemente niza koji nisu deljivi
   svojom poslednjom cifrom. Povratna vrednost funkcije je
   broj elemenata rezultujuceg niza. */
int brisanje(int a[], int n)
{
  int i, j, poslednja_cifra;
  
  /* Obilaze se svi elementi niza a. */
  for (i = 0, j = 0; i < n; i++) 
  {
    /* Izdvaja se poslednja cifra tekuceg elementa. */
    poslednja_cifra = a[i] % 10;

    /* Ako je poslednja cifra nula ili je element deljiv svojom
       poslednjom cifrom, taj element se zadrzava i smesta na
       poziciju j. */
    if (poslednja_cifra == 0 || a[i] % poslednja_cifra == 0) 
    {
      a[j] = a[i];
      j++;
    }
  }
  
  return j;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n;

  /* Ucitavaju se dimenzija i elementi niza. */
  n = ucitaj(a);

  /* Brisu se svi elementi koji nisu deljivi svojom poslednjom
     cifrom. */
  n = brisanje(a, n);

  /* Ispisuje se rezultujuci niz. */
  printf("Niz a nakon izmena:\n");
  ispisi(a, n);

  exit(EXIT_SUCCESS);
}
