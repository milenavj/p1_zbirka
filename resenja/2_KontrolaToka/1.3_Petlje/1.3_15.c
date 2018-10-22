#include <stdio.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  float cena, m;
  int n, i;
  int broj_artikala = 0;

  /* Ucitava se vrednost broja m. */
  printf("Nikolin budzet: ");
  scanf("%f", &m);

  /* Vrsi se provera ispravnosti ulaza. */
  if (m < 0) {
    printf("Greska: neispravan unos novca.\n");
    return -1;
  }

  /* Ucitava se broj n. */
  printf("Unesite broj artikala: ");
  scanf("%d", &n);

  /* Vrsi se provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: neispravan unos broja artikala.\n");
    return -1;
  }

  /* Unose se cene artikala i racuna se rezultat. */
  printf("Unesite cene artikala: ");
  
  for(i=0; i<n; i++){
    /* Ucitava se cena artikla. */
    scanf("%f", &cena);

    /* Vrsi se provera ispravnosti vrednosti cene. */
    if (cena <= 0) {
      printf("Greska: neispravan unos cene.\n");
      return -1;
    }

    /* Provera se da li Nikola moze da kupi trenutni artikal. */
    if (cena <= m)
      broj_artikala++;
  }

  /* Ispis rezultata. */
  printf("Ukupno artikala: %d\n", broj_artikala);

  return 0;
}
