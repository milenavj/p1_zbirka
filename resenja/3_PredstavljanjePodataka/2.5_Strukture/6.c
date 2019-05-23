#include <stdio.h>
#include <stdlib.h>

#define MAKS_PODATAKA 50
#define MAKS_NAZIV 21

typedef struct {
  char naziv_prodavnice[MAKS_NAZIV];
  double cena_artikla;
} Artikal;

/* Funkcija ucitava podatke o ceni artikla u razlicitim
   prodavnicama. */
void ucitaj(Artikal niz[], int n) {
  int i;
  printf("Unesite podatke o cenama:\n");
  for (i = 0; i < n; i++) {
    scanf("%s%lf", niz[i].naziv_prodavnice, &niz[i].cena_artikla);
    if (niz[i].cena_artikla <= 0) {
      printf("Greska: neispravan unos.\n");
      exit(EXIT_FAILURE);
    }
  }
}

/* Funkcija ispisuje imena svih prodavnica u kojima je cena artikla 
   manja ili jednaka zeljenoj ceni. */
void ispisi(Artikal niz[], int n, double zeljena_cena) {
  int i;
  printf("Povoljne prodavnice su:\n");
  for (i = 0; i < n; i++)
    if (niz[i].cena_artikla <= zeljena_cena)
      printf("%s\n", niz[i].naziv_prodavnice);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  Artikal niz[MAKS_PODATAKA];
  double zeljena_cena;
  int n;

  /* Ucitavanje broja prodavnica i provera ispravnosti ulaza. */
  printf("Unesite broj prodavnica: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS_PODATAKA) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje podataka o cenama. */
  ucitaj(niz, n);

  /* Ucitavanje zeljene cene. */
  printf("Unesite zeljenu cenu: ");
  scanf("%lf", &zeljena_cena);

  /* Ispis rezultata. */
  ispisi(niz, n, zeljena_cena);

  return 0;
}
