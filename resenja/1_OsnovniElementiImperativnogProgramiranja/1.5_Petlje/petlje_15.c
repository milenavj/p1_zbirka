#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int n, cifra, n_original;
  int pronadjena_petica = 0;

  /* Ucitavanje vrednosti broja n. */
  printf("Unesite broj: ");
  scanf("%d", &n);

  /* Cuvanje originalne vrednosti unetog broja. */
  n_original = n;

  /* Uzimanje apsolutne vrednosti unetog broja. */
  if (n < 0)
    n = abs(n);

  /* Petlja se izvrsava dok god ima cifara u broju. */
  while (n > 0) {
    /* Izdvajanje poslednje cifre broja. */
    cifra = n % 10;

    /* Provera da li je ona jednaka broju 5. */
    if (cifra == 5) {
      /* Ako jeste, vrednost odgovarajuceg indikatora se postavlja
         na 1 i petlja se prekida. */
      pronadjena_petica = 1;
      break;
    }

    /* Ako petlja nije prekinuta, iz broja se uklanja poslednja
       cifra i postupak se ponavlja dok god ima neobradjenih
       cifara. */
    n = n / 10;
  }

  /* Ispis rezultata. Napomena: Koristi se unapred zapamcena
     promenljiva n_original jer je promenljiva n izmenjena u
     petlji. */
  if (pronadjena_petica == 0)
    printf("Broj %d sadrzi cifru 5.\n", n_original);
  else
    printf("Broj %d ne sadrzi cifru 5.\n", n_original);

  return 0;
}
