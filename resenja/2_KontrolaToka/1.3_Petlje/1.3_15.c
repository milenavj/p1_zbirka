#include <stdio.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  float cena, m;
  unsigned int n, i, broj_artikala = 0;

  /* Ucitava se vrednost broja m. */
  printf("Nikolin budzet: ");
  scanf("%f", &m);

  /* Ucitava se broj artikala. */
  printf("Unesite broj artikala: ");
  scanf("%u", &n);

  /* Unose se cene artikala i racuna se rezultat. */
  printf("Unesite cene artikala: ");
  
  for(i=0; i<n; i++){
    /* Ucitava se cena artikla. */
    scanf("%f", &cena);

    /* Provera se da li Nikola moze da kupi trenutni artikal. */
    if (cena <= m)
      broj_artikala++;
  }

  /* Ispis rezultata. */
  printf("Ukupno artikala: %d\n", broj_artikala);

  return 0;
}
