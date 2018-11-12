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

void promeni_redosled(int niz[], int n)
{
  int i = 0, j = n - 1;
  int pom;  

  /* Krece se sa pocetka niza (po brojacu i) i sa kraja niza (po
     brojacu j) i svaki put kada se naidje na elemente koji po 
     parnosti ne odgovaraju delu niza u kome treba da budu, ti
     elementi se zamene. */
  while (i < j && i < n && j >= 0) 
  {
    if (niz[i] % 2 != 0 && niz[j] % 2 == 0) 
    {
      pom = niz[i];
      niz[i] = niz[j];
      niz[j] = pom;
    }

    /* Ukoliko je element na poziciji i paran, prelazi se na
       sledeci element niza, brojac i se uvecava. */
    if (niz[i] % 2 == 0)
      i++;

    /* Ukoliko je element na poziciji j neparan, prelazi se na
       sledeci element niza, brojac j se smanjuje. */
    if (niz[j] % 2 != 0)
      j--;
  }  
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int niz[MAKS];
  int n;

  /* Ucitavaju se dimenzija i elemenati niza. */
  n = ucitaj(niz);

  /* Menja se niz na trazeni nacin. */
  promeni_redosled(niz, n);
  
  /* Ispis rezultata. */
  printf("Rezultujuci niz:\n");
  ispisi(niz, n);

  exit(EXIT_SUCCESS);
}
