#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_IME 21
#define BROJ_CIFARA 10

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  char c;
  char ime_datoteke[MAKS_IME];
  int brojaci[BROJ_CIFARA];
  int i, maks;

  /* Ucitavanje imena ulazne datoteke. */
  printf("Unesite ime datoteke: ");
  scanf("%s", ime_datoteke);

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(ime_datoteke, "r");
  if (ulaz == NULL) {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke.\n");
    exit(EXIT_FAILURE);
  }

  /* Brojaci za cifre se inicijalizuju na nule. Indeks niza brojaci 
     oznacava cifru (brojaci[0] se koristi za prebrojavanje cifre
     0, brojaci[1] za 1, ..., brojaci[9] za cifru 9). */
  for (i = 0; i < BROJ_CIFARA; i++)
    brojaci[i] = 0;

  /* Citanje karaktera i uvecavanje odgovarajucih brojaca. */
  while ((c = fgetc(ulaz)) != EOF) {
    if (isdigit(c))
      brojaci[c - '0']++;
  }

  /* Pronalazak cifre koja se najvise puta pojavljuje u datoteci. */
  maks = brojaci[0];
  for (i = 1; i < BROJ_CIFARA; i++)
    if (brojaci[i] > maks)
      maks = brojaci[i];

  /* Ispis rezultata. */
  if(maks == 0)
    printf("Datoteka ne sadrzi cifre.\n");
  else {
    printf("Najcesce cifre: ");
    for (i = 0; i < BROJ_CIFARA; i++)
      if (brojaci[i] == maks)
        printf("%d ", i);
    printf("\n");
  }
    
  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
