#include <stdio.h>
#include <stdlib.h>

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE * ulaz, *izlaz;
  int c; 
 
  /* Datoteka ulaz.txt se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */
  ulaz = fopen("ulaz.txt", "r");
  if (ulaz == NULL) 
  {    
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
                    "ulaz.txt.\n");
    exit(EXIT_FAILURE);
  }
  
  /* Datoteka izlaz.txt se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */
  izlaz = fopen("izlaz.txt", "w");
  if (izlaz == NULL) 
  {
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
                    "izlaz.txt. \n");
    exit(EXIT_FAILURE);
  }

  /* Iz ulazne datoteke se citaju karakteri i svaki treci karakter
     se upisuje u izlaznu datoteku. */ 
  while ((c = fgetc(ulaz)) != EOF) 
  {
    /* Procitani karakter se upisuje u izlaznu datoteku. */
    fputc(c, izlaz);
    
    /* Naredna dva karaktera se preskacu. */
    fgetc(ulaz);
    fgetc(ulaz);
  }
 
  /* Zatvaraju se otvorene datoteke. */ 
  fclose(izlaz);
  fclose(ulaz);
  
  return 0;
}