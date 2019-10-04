#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  int c, broj_malih = 0;

  /* Otvaranje datoteke podaci.txt za citanje i provera uspeha. */ 
  ulaz = fopen("podaci.txt", "r");
  if (ulaz == NULL)
  {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
            "podaci.txt.\n");
    exit(EXIT_FAILURE);
  }

  /* Citanje karaktera i prebrojavanje malih slova. */
  while ((c = fgetc(ulaz)) != EOF)
    if (islower(c))
      broj_malih++;

  /* Ispis rezultata. */
  printf("Broj malih slova je: %d\n", broj_malih);
  
  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);

}
