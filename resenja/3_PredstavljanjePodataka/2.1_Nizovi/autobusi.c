#include <stdio.h>
#include <stdlib.h>

/* Indeksiranje pocinje od 1, pa zato maksimalna dimenzija niza
   mora biti 201, a ne 200. */
#define MAKS 201

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, niz[MAKS], i;
  int k, t, kasnjenje;

  /* Ucitava se dimenzija niza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se vremena putovanja. */
  printf("Unesite vreme putovanja:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &niz[i]);

  /* Ucitavaju se redni brojevi autobusa cije se vreme putovanja
     menja.  */
  printf("Unesite redne brojeve autobusa koji"
        " putuju na potezu Pozega, Uzice:\n");
  scanf("%d%d", &k, &t);

  /* Vrsi se provera ispravnosti ulaza. */
  if (k <= 0 || k > n || t <= 0 || t > n) {
    printf("Redni brojevi autobusa nisu u dozvoljenom opsegu.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitava se vrednost kasnjenja. */
  printf("Unesite novo vreme:\n");
  scanf("%d", &kasnjenje);

  /* Vrsi se provera ispravnosti ulaza. */
  if (kasnjenje < 0) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Azuriraju se vremena putovanja. */
  for (i = k; i <= t; i++)
    niz[i] += kasnjenje;

  /* Ispis rezultata. */
  printf("Vreme putovanja nakon izmena:");
  for (i = 1; i <= n; i++)
    printf("%d ", niz[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
