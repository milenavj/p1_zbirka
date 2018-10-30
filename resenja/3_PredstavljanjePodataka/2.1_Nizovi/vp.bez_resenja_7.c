#include <stdio.h>
#include <stdlib.h>

#define MAKS 10

/* Funkcija koja ucitava elemente niza. */
void unos(int niz[])
{
  int i;
  printf("Unesite %d brojeva:\n", MAKS);
  for (i = 0; i < MAKS; i++)
    scanf("%d", &niz[i]);
}

/* Funkcija koja ispisuje elemente niza. */
void ispis(int niz[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int niz[MAKS];
  int i = 0, j = MAKS - 1;
  int pom;

  /* Ucitavanje niza. */
  unos(niz);

  /* Krece se sa pocetka niza (po brojacu i) i sa kraja niza (po
     brojacu j) i svaki put kada se naidje na elemente koji po 
     parnosti ne odgovaraju delu niza u kome treba da budu, ti
     elementi se zamene. */
  while (i < j && i < MAKS && j >= 0) {
    if (niz[i] % 2 != 0 && niz[j] % 2 == 0) {
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

  /* Ispis rezultata. */
  printf("Rezultujuci niz:\n");
  ispis(niz, MAKS);

  exit(EXIT_SUCCESS);
}
