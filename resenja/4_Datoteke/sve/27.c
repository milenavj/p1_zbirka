#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_LINIJA 81

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  char linija[MAKS_LINIJA];
  char najduza_linija[MAKS_LINIJA];
  int duzina;
  int maks_duzina;
  FILE *ulaz;

  /* Provera broja argumenata komandne linije. */
  if (argc != 2) 
    greska("Greska: neispravan poziv.\n");

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */  
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");

  /* Pronalazi se najduza linija u fajlu. */
  maks_duzina = 0;
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) 
  {
    duzina = strlen(linija);

    if (duzina > maks_duzina || 
       (duzina == maks_duzina && strcmp(linija, najduza_linija) < 0)) 
    {
      strcpy(najduza_linija, linija);
      maks_duzina = duzina;
    }
  }

  /* Ispis najduze linije na standardni izlaz. */
  printf("%s", najduza_linija);

  /* Zatvara se datoteka. */ 
  fclose(ulaz);
  
  return 0;
}
