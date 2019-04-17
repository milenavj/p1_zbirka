#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_REC 201

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija proverava da li je prosledjena rec palindrom.
   Pri proveri se ignorise razlika izmedju malih i velikih slova. */
int palindrom(char rec[])
{
  int n = strlen(rec);
  int i;

  for (i = 0; i < n / 2; i++)
    if (tolower(rec[i]) != tolower(rec[n - i - 1]))
      return 0;

  return 1;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char rec[MAKS_REC];

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */ 
  ulaz = fopen("razno.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");

  /* Izlazna datoteka se otvara za pisanje i proverava se da li je
     otvaranje proslo uspesno. */ 
  izlaz = fopen("palindromi.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.\n");

  /* Iz datoteke se cita rec po rec i u izlaznu datoteku se upisuju
     reci koje su palindromi. */
  while (fscanf(ulaz, "%s", rec) != EOF) 
  {
    if (palindrom(rec))
      fprintf(izlaz, "%s ", rec);
  }

  /* Zatvaraju se datoteke. */  
  fclose(ulaz);
  fclose(izlaz);
  
  return 0;
}