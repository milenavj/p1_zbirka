#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int niz[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", niz[i]);
  printf("\n");
}

/* Funkcija razmenjuje elemente niza tako da se na pocetku niza
   nalaze svi parni elementi niza, a zatim svi neparni elementi
   niza. */
void promeni_redosled(int niz[], int n) {
  int i = 0, j = n - 1, pom;

  /* Krece se od pocetka niza (po brojacu i) i od kraja niza (po
     brojacu j) i svaki put kada se naidje na elemente koji po
     parnosti ne odgovaraju delu niza u kome treba da budu,
     zamene se njihove vrednosti. */
  while (i < j && i < n && j >= 0) {
    if (niz[i] % 2 != 0 && niz[j] % 2 == 0) {
      pom = niz[i];
      niz[i] = niz[j];
      niz[j] = pom;
    }

    /* Ukoliko je element na poziciji i paran, Prelazak na
       sledeci element niza, brojac i se uvecava. */
    if (niz[i] % 2 == 0)
      i++;

    /* Ukoliko je element na poziciji j neparan, Prelazak na
       sledeci element niza, brojac j se smanjuje. */
    if (niz[j] % 2 != 0)
      j--;
  }
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int niz[MAKS];
  int n;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(niz, n);

  /* Izmena niza na trazeni nacin. */
  promeni_redosled(niz, n);

  /* Ispis rezultata. */
  printf("Rezultujuci niz:\n");
  ispisi(niz, n);

  exit(EXIT_SUCCESS);
}
