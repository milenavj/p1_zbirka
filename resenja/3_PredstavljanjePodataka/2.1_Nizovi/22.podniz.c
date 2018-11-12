#include <stdio.h>
#include <stdlib.h>
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

/* Resenje pod a. */
int podniz_uzastopnih(int a[], int n, int b[], int m)
{
  int i, j;

  /* Prolaze se elementi prvog niza. Svaki element prvog niza moze
     biti pocetak podniza, odnosno pocetak drugog niza. */
  for (i = 0; i + m - 1 < n; i++) 
  {
    /* Prolaze se elementi drugog niza. Za svaki element niza b
       proverava se da li je jednak odgovarajucem elementu niza a.
       Za niz a razmatra se da li podniz pocinje od pozicije i. Tako 
       0-ti element niza b je na poziciji i, 1. element je na
       poziciji i+1, 2. na poziciji i+2, ..., j-ti na poziciji
       i+j. Ako uslov nije ispunjen, petlja se prekida i proverava
       se da li na sledecoj poziciji u nizu a pocinje podniz. */
    for (j = 0; j < m; j++)
      if (a[i + j] != b[j])
        break;
    /* Ako petlja nije prekinuta nakon ispitivanja, brojac za niz b 
       je jedanak dimenziji niza b, odnosno svi elementi niza b se
       uzastopno nalaze u nizu a. */
    if (j == m)
      return 1;
  }

  /* Ukoliko niz b jeste uzastopni podniz uslov u petlji ce u nekom 
     trenutku biti ispunjen i iz petlje i funkcije ce se izaci sa
     return naredbom. Ipak, ako se to nije desilo i dalje se
     izvrsava funkcija, onda niz b nije uzastopni podniz. */
  return 0;
}

/* Resenje pod b. */
int podniz(int a[], int n, int b[], int m)
{
  int i, j;

  /* Petljom se prolaze elementi niza a. */
  for (i = 0, j = 0; i < n && j < m; i++)
  {
    /* Svaki put kada se naidje na element niza b, brojac za niz b
       se uvecava i proverava se da li se sledeci element niza b
       nalazi u nizu a. */
    if (a[i] == b[j])
      j++;
  }
  
  /* Ukoliko se pronadju svi elementi niza b u nizu a, onda je
     brojac za niz b jednak dimenziji niza b. U tom slucaju se
     vraca vrednost 1, odnosno da niz jeste podniz. */
  return j == m;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, a[MAKS];
  int m, b[MAKS];

  /* Ucitavanje nizova. */
  n = ucitaj(a);
  m = ucitaj(b);

  /* a) */
  if (podniz_uzastopnih(a, n, b, m))
    printf("Elementi drugog niza cine uzastopni podniz "
           "prvog niza.\n");
  else
    printf("Elementi drugog niza ne cine uzastopni podniz "
         "prvog niza.\n");

  /* b) */
  if (podniz(a, n, b, m))
    printf("Elementi drugog niza cine podniz prvog niza.\n");
  else
    printf("Elementi drugog niza ne cine podniz prvog niza.\n");

  exit(EXIT_SUCCESS);
}
