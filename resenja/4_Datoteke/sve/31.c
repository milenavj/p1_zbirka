#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
  char linija[MAKS_LINIJA];
  FILE * izlaz;
  int ispisi_v = 0, ispisi_m = 0;
  
  if (argc > 2) 
    greska("Greska: neispravan poziv.\n");

  if (argc == 1)
    ispisi_v = ispisi_m = 1;
  else 
  {
    /* Funkcija strcasecmp poredi niske ignorisuci razliku izmedju
       malih i velikih slova. */
    if (strcasecmp(argv[1], "-v") == 0)
      ispisi_v = 1;
    else if (strcasecmp(argv[1], "-m") == 0)
      ispisi_m = 1;
    else 
      greska("Greska: neispravna opcija.\n");
  }

  izlaz = fopen("izlaz.txt", "w");
  if (izlaz == NULL) 
    greska("Greska: neuspesno otvaranje izlazne datoteke.\n");

  while (fgets(linija, MAKS_LINIJA, stdin) != NULL) 
  {
    if ((ispisi_m && islower(linija[0])) || 
        (ispisi_v && isupper(linija[0])) || 
        (ispisi_m && ispisi_v))
      fputs(linija, izlaz);
  }

  /* Zatvara se datoteka. */ 
  fclose(izlaz);

  return 0;
}