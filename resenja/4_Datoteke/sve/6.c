#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE * ulaz;
  int c, broj_malih = 0;

  /* Datoteka podaci.txt se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */
  ulaz = fopen("podaci.txt", "r");
  if (ulaz == NULL) 
  {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
                    "podaci.txt.\n");
    exit(EXIT_FAILURE);
  }

  /* Cita se karakter po karakter i prebrojavaju se mala slova. */
  while ((c = fgetc(ulaz)) != EOF) 
  {
    if (islower(c))
      broj_malih++;
  }

  /* Ispis rezultata. */ 
  printf("Broj malih slova je: %d\n", broj_malih);

  /* Zatvara se datoteka.*/ 
  fclose(ulaz);

  return 0;
}