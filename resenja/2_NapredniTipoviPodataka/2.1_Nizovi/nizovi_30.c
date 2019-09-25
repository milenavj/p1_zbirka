#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n) {
  int i;
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija ispisuje elemente niza dimenzije n. */
void ispisi(int a[], int n) {
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

/* Funkcija vraca 1 ako je broj prost, a 0 u suprotnom.  */
int prost(int x) {
  int i;

  /* Brojevi 2 i 3 su prosti. */
  if (x == 2 || x == 3)
    return 1;

  /* Parni brojevi nisu prosti. */
  if (x % 2 == 0)
    return 0;

  /* Ako se naidje na broj koji deli broj x, onda broj x nije
     prost. Provera se vrsi za sve neparne brojeve izmedju 3 i
     korena broja x, jer kada bi x imao parnog delioca, onda bi
     i broj 2 delio x, a taj uslov je vec proveren. */
  int koren_x = sqrt(x);
  for (i = 3; i <= koren_x; i += 2)
    if (x % i == 0)
      return 0;

  /* Ako nijedan od prethodnih uslova nije bio ispunjen, to znaci
     da nijedan broj ne deli x, pa je on prost. */
  return 1;
}

/* Funkcija od niza a formira niz b koji sadrzi sve elemente niza a 
   koji nisu prosti brojevi. Povratna vrednost funkcije je broj
   elemenata niza b. */
int obrisi_proste(int a[], int n, int b[]) {
  int i, j;

  /* Kada se u nizu a naidje na prost element, on se upisuje u niz
     b i Uvecavanje brojac za niz b. */
  for (i = 0, j = 0; i < n; i++)
    if (prost(a[i]) == 0) {
      b[j] = a[i];
      j++;
    }

  return j;
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS], b[MAKS];
  int n_a, n_b;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n_a);
  if (n_a <= 0 || n_a > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje elemenata niza. */
  ucitaj(a, n_a);

  /* Formira se niz b brisanjem prostih brojeva iz niza a. */
  n_b = obrisi_proste(a, n_a, b);

  /* Ispis elemenata niza b. */
  printf("Rezultujuci niz:\n");
  ispisi(b, n_b);

  exit(EXIT_SUCCESS);
}
