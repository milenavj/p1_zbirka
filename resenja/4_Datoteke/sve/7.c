#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_IME 21
#define MAKS_CIFARA 10

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  char c;
  char ime_datoteke[MAKS_IME];
  int brojaci[MAKS_CIFARA];
  int i, maks_i;

  /* Ucitavanje imena ulazne datoteke. */
  printf("Unesite ime datoteke: ");
  scanf("%s", ime_datoteke);

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */
  ulaz = fopen(ime_datoteke, "r");
  if (ulaz == NULL) 
  {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke.\n");
    exit(EXIT_FAILURE);
  }

  /* Brojaci za cifre se inicijalizuju na nule. 
     Indeks niza brojaci oznacava cifru (brojaci[0] se koristi za 
     prebrojavanje cifre 0, brojaci[1] za 1, ..., brojaci[9] za
     cifru 9).*/
  for (i = 0; i < MAKS_CIFARA; i++)
    brojaci[i] = 0;

  /* Iz datoteke se cita karakter po karakter i za svaku procitanu
     cifru se uvecava odgovarajuci brojac. */
  while ((c = fgetc(ulaz)) != EOF) 
  {
    if (isdigit(c))
      brojaci[c - '0']++;
  }

  /* Pronalazi se cifra koja se najvise puta pojavljuje u
     datoteci. */
  maks_i = 0;
  for (i = 1; i < MAKS_CIFARA; i++)
    if (brojaci[maks_i] < brojaci[i])
      maks_i = i;

  /* Ispis rezultata. */
  printf("%d\n", maks_i);

  /* Zatvara se datoteka. */  
  fclose(ulaz);
  
  return 0;
}
