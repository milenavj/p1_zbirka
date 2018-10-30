#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija vraca poziciju najveceg elementa niza. */
int pozicija_najveceg(int a[], int n)
{
  int i, pozicija = 0;
  /* Prolazi se kroz niz i ako se naidje na element cija je
     vrednost veca od trenutno najveceg (a[pozicija]), vrsi
     se azuriranje pozicije trenutno najveceg. */
  for(i=1; i<n; i++)
    if(a[i] > a[pozicija])
      pozicija = i;
    
  return pozicija;
}

/* Funkcija vraca broj parnih elemenata niza koji prethode
   maksimalnom elementu niza. */
int prebrojavanje(int a[], int n)
{
  int i;
  int pozicija_maksimuma = pozicija_najveceg(a,n);

  int broj_parnih = 0;
  for (i = 0; i < pozicija_maksimuma; i++) {
    if (a[i] % 2 == 0) {
      broj_parnih++;
    }
  }

  return broj_parnih;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n, i;

  /* Ucitava se broj elemenata niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj elemenata niza:");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza:");
  for (i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  /* Ispis rezultata. */
  printf("%d\n", prebrojavanje(a, n));

  exit(EXIT_SUCCESS);
}
