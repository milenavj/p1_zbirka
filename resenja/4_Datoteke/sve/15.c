#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_REC 201
#define ZBIR 1000

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija racuna zbir ASCII kodova karaktera prosledjene reci. */
int zbir(char *rec)
{
  int i = 0;
  int suma = 0;

  while (rec[i]) 
  {
    suma += rec[i];
    i++;
  }

  return suma;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char rec[MAKS_REC];

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */ 
  ulaz = fopen("ulaz.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");
  
  /* Izlazna datoteka se otvara za pisanje i proverava se da li je
     otvaranje proslo uspesno. */ 
  izlaz = fopen("izlaz.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.\n");

  /* Iz datoteke se cita rec po rec i ukoliko je odgovarajuci zbir
     veci od vrednosti ZBIR, tada se rec ispisuje u izlaznu
     datoteku. */
  while (fscanf(ulaz, "%s", rec) != EOF) 
  {
    if (zbir(rec) > ZBIR)
      fprintf(izlaz, "%s ", rec);
  }

  /* Zatvaraju se datoteke. */  
  fclose(ulaz);
  fclose(izlaz);
  
  return 0;
}