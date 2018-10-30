#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS 100

/* Funkcija vraca 1 ako je broj prost, a 0 u suprotnom.  */
int prost(int x){
  int i;

  /* Brojevi 2 i 3 su prosti. */
  if (x == 2 || x == 3)
    return 1;

  /* Parni brojevi nisu prosti. */
  if (x % 2 == 0)
    return 0;

  /* Ako se naidje na broj koji deli broj x, onda broj x nije
     prost. Provera se vrsi za sve neparne brojeve izmedju 3 i 
     sqrt(x), jer kada bi x imao parnog delioca, onda bi i broj 2
     delio x, a taj uslov je vec proveren. */
  for (i = 3; i <= sqrt(x); i += 2)
    if (x % i == 0)
      return 0;

  /* Ako nijedan od prethodnih uslova nije bio ispunjen, to znaci
     da nijedan broj ne deli x, pa je on prost. */
  return 1;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS], b[MAKS];
  int i, j, n_a, n_b;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite broj elemenata niza: ");
  scanf("%d", &n_a);
  if (n_a < 1 || n_a > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza a. */
  printf("Unesite elemente niza: ");
  for (i = 0; i < n_a; i++)
    scanf("%d", &a[i]);

  /* Kada se u nizu a naidje na prost element, on se upisuje u niz
     b i uvecava se brojac za niz b. */
  for (i = 0, j = 0; i < n_a; i++) {
    if (prost(a[i]) == 0) {
      b[j] = a[i];
      j++;
    }
  }

  /* Broj elemenata novodobijenog niza b je j. */
  n_b = j;

  /* Ispisuju se elementi niza b. */
  for (i = 0; i < n_b; i++)
    printf("%d ", b[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
