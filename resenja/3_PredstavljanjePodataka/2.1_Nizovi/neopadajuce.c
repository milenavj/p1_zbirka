#include <stdio.h>
#include <stdlib.h>

#define MAKS 300

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, niz[MAKS], i;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz[i]);


  /* Provera da li su elementi niza uredjeni neopadajuce. */
  for (i = 0; i < n - 1; i++)
    /* Porede se svaka dva uzastopna elementa niza. Ukoliko za bilo 
       koja takva dva elementa uslov nije ispunjen, prekida se
       dalje ispitivanje i vraca se poruka da niz nije uredjen
       neopadajuce. U suprotnom se nakon izlaska iz petlje ispisuje 
       poruka da je niz uredjen neopadajuce. */
    if (niz[i] > niz[i + 1]) {
      printf("Nije uredjen neopadajuce.\n");
      exit(EXIT_SUCCESS);
    }

  printf("Jeste uredjen neopadajuce.\n");
  exit(EXIT_SUCCESS);
}
