#include <stdio.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  int sati, minuti;
  int preostali_sati, preostali_minuti;

  /* Ucitavanje podataka o vremenu. Napomena: Vreme se zadaje u
     formatu sat:minut. Iz tog razloga je i odgovarajuci format u
     funkciji scanf %d:%d. */
  printf("Unesite vreme: ");
  scanf("%d:%d", &sati, &minuti);

  /* Provera ispravnosti ulaznih podataka. */
  if (sati > 24 || sati < 0 || minuti > 59 || minuti < 0) {
    printf("Greska: neispravan unos vremena.\n");
    return -1;
  }

  /* Racunanje preostalog vremena. */
  preostali_sati = 24 - sati - 1;
  preostali_minuti = 60 - minuti;

  if (preostali_minuti == 60) {
    /* Uvecavanje vrednosti broja za 1 se moze uraditi na vise
       nacina. Neki od njih su: 
       broj = broj + 1; 
       broj += 1;
       broj++; */
    preostali_sati++;
    preostali_minuti = 0;
  }

  /* Ispis rezultata. */
  printf("Do ponoci: %d sati i %d minuta\n",
         preostali_sati, preostali_minuti);

  return 0;
}
