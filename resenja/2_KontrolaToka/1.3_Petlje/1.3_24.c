#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, i;
  int x, x_kopija, vodeca_cifra;
  int najveca_vodeca_cifra, rezultat;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj n: ");
  scanf("%d", &n);

  /* Provera ispravnosti ulaza. */
  if (n < 0) {
    printf("Greska: neispravan unos.\n");
    return -1;
  }

  /* Ako nema unetih brojeva, ispisuje se odgovarajuca poruka. */
  if (n == 0) {
    printf("Nisu uneti brojevi.\n");
    return 0;
  }

  /* Inicijalizacija najvece vodece cifre na -1. */
  najveca_vodeca_cifra = -1;

  printf("Unesite n brojeva: ");
  for (i = 0; i < n; i++) {
    scanf("%d", &x);

    /* Racunanje vodece cifre ucitanog broja x. */
    x_kopija = abs(x);
    while (x_kopija > 10) {
      x_kopija = x_kopija / 10;
    }
    vodeca_cifra = x_kopija;

    /* Ako je izdvojena cifra veca od najvece vodece cifre,
       azuriraju se vrednosti najvece vodece cifre i rezultata. */
    if (vodeca_cifra > najveca_vodeca_cifra) {
      najveca_vodeca_cifra = vodeca_cifra;
      rezultat = x;
    }
  }

  /* Ispis rezultata. */
  printf("%d\n", rezultat);

  return 0;
}
