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

int obrisi_neparne(int a[], int n)
{
  int i, j;
  /* Promenljiva j predstavlja brojac prve slobodne pozicije na koju
     se moze upisati element niza koji treba da ostane u nizu. Kada 
     se naidje na element koji je paran, on se kopira na mesto a[j] 
     i poveca se vrednost brojaca j. Ukoliko se naidje na element
     koji je neparan, njega treba preskociti. */
  for (i = 0, j = 0; i < n; i++) 
  {
    /* Ako je tekuci element niza a paran. */
    if (a[i] % 2 == 0) 
    {
      /* Premesta se na poziciju j. */
      a[j] = a[i];

      /* Vrednost brojaca j se priprema za narednu iteraciju. */
      j++;
    }
    /* Ako je tekuci element niza a neparan, sa njim nista ne treba 
       raditi. */
  }
  
  /* Rezultujuci niz ima j elemenata. */
  return j;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n;

  /* Ucitavaju se dimenzija i elementi niza. */
  n = ucitaj(a);

  /* Brisu se neparni elementi. */
  n = obrisi_neparne(a, n);

  /* Ispisuju se elementi modifikovanog niza a. */
  ispisi(a, n);

  exit(EXIT_SUCCESS);
}
