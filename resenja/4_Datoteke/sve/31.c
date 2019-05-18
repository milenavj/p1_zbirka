#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAKS_LINIJA 81

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  /* Deklaracije potrebnih promenljivih. */
  char linija[MAKS_LINIJA];
  FILE *izlaz;
  int ispis_velika_slova = 0, ispis_mala_slova = 0;

  /* Provera broja argumenata komandne linije. */
  if (argc > 2)
    greska("Greska: neispravan poziv.");

  /* Postavljanje vrednosti indikatora za ispis u zavisnosti od
     navedene opcije. */
  if (argc == 1)
    ispis_velika_slova = ispis_mala_slova = 1;
  else {
    /* Funkcija strcasecmp poredi niske ignorisuci razliku izmedju
       malih i velikih slova. */
    if (strcasecmp(argv[1], "-v") == 0)
      ispis_velika_slova = 1;
    else if (strcasecmp(argv[1], "-m") == 0)
      ispis_mala_slova = 1;
    else
      greska("Greska: neispravna opcija.");
  }

  /* Otvaranje datoteke izlaz.txt za pisanje i provera uspeha. */   
  izlaz = fopen("izlaz.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Citanje linija sa standardnog ulaza i ispis odgovarajucih 
     linija u izlaznu datoteku. */
  while (fgets(linija, MAKS_LINIJA, stdin) != NULL) {
    if ((ispis_mala_slova && islower(linija[0])) ||
        (ispis_velika_slova && isupper(linija[0])) || 
        (ispis_mala_slova && ispis_velika_slova))
      fputs(linija, izlaz);
  }

  /* Zatvaranje datoteke. */
  fclose(izlaz);

  return 0;
}