#include <stdio.h>
#include <stdlib.h>

#define MAKS 300

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

/* Funkcija koja vraca 1 ako je niz uredjen neopadajuce, 
   a nulu inace. */
int uredjen_neopadajuce(int niz[], int n)
{
  int i;
  for (i = 0; i < n - 1; i++)
  {
    if (niz[i] > niz[i + 1])
      return 0;
  }
  
  return 1;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, niz[MAKS];

  /* Ucitavaju se dimenzija i elementi niza. */
  n = ucitaj(niz);

  /* Ispis rezultata. */
  if(uredjen_neopadajuce(niz, n))
    printf("Niz jeste uredjen neopadajuce.\n");
  else
    printf("Niz nije uredjen neopadajuce.\n");
  
  exit(EXIT_SUCCESS);
}
