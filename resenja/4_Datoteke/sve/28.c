#include <stdio.h>
#include <string.h>
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
  /* Deklaracije potrebnih promenljivih. */
  FILE * ulaz;
  char linija[MAKS_LINIJA];
  int k;
 
  /* Proverava se da li je program ispravno pozvan. */ 
  if (argc != 3) 
    greska("Greska: neispravan poziv.");
  
  /* Otvara se datoteka cije se ime zadaje kao prvi argument 
     komandne linije i proverava se da li je otvaranje proslo
     uspesno. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL) 
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");
  
  /* Cita se brojevna vrednost drugog argumenta komandne linije. */
  k = atoi(argv[2]);
  
  /* Funkcija fgets cita jednu liniju iz datoteke. 
     Prima tri argumenta:
     1. Niska u koju ce biti smestena procitana linija
     2. Maksimalna duzina linije
     3. Datoteku iz koje se cita. 
     Kada dodje do kraja datoteke, kao povratnu vrednost
     vraca NULL. */
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) 
  { 
    /* Na standardni izlaz se ispisuju sve linije iz datoteke
       cija je duzina veca od k. */
    if (strlen(linija) > k) 
      printf("%s", linija);
  }
  printf("\n");
  
  /* Zatvara se datoteka. */ 
  fclose(ulaz);
  
  return 0;
}
