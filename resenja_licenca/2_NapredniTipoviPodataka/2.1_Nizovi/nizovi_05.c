/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Indeksiranje autobusa pocinje od 1, pa zato maksimalna
   dimenzija niza mora biti 201, a ne 200. */
#define MAKS 201

int main() {
  /* Deklaracija potrebnih promenljivih. */
  int n, niz[MAKS], i;
  int k, t, m;

  /* Ucitavanje dimenzije niza i provera ispravnosti ulaza. */
  printf("Unesite broj autobusa: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavanje vremena putovanja. */
  printf("Unesite vreme putovanja:\n");
  for (i = 1; i <= n; i++)
    scanf("%d", &niz[i]);

  /* Ucitavanje rednih brojeva autobusa cije se vreme putovanja
     menja i vrednosti kasnjenja. */
  printf("Unesite vrednosti k, t i m:\n");
  scanf("%d%d%d", &k, &t, &m);

  /* Provera ispravnosti ulaza. */
  if (k <= 0 || k > n || t <= 0 || t > n || m < 0) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Azuriranje vremena putovanja. */
  for (i = k; i <= t; i++)
    niz[i] += m;

  /* Ispis rezultata. */
  printf("Vreme putovanja nakon izmena: ");
  for (i = 1; i <= n; i++)
    printf("%d ", niz[i]);
  printf("\n");

  exit(EXIT_SUCCESS);
}
