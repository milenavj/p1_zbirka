#include <stdio.h>
#include <stdlib.h>

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  int c;

  /* Otvaranje datoteke ulaz.txt za citanje i provera uspeha. */
  ulaz = fopen("ulaz.txt", "r");
  if (ulaz == NULL){
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
            "ulaz.txt.\n");
    exit(EXIT_FAILURE);
  }

  /* Otvaranje datoteke izlaz.txt za pisanje i provera uspeha. */
  izlaz = fopen("izlaz.txt", "w");
  if (izlaz == NULL){
    fprintf(stderr, "Greska: neuspesno otvaranje datoteke "
            "izlaz.txt. \n");
    exit(EXIT_FAILURE);
  }

  /* Citanje karaktera iz ulazne datoteke. */
  while ((c = fgetc(ulaz)) != EOF){
    /* Upisivanje procitanog karaktera u izlaznu datoteku. */
    fputc(c, izlaz);

    /* Preskakanje naredna dva karaktera. */
    fgetc(ulaz);
    fgetc(ulaz);
    
    /* Ovakvo resenje ce raditi i u slucaju kada broj karaktera u
       datoteci nije deljiv sa 3 jer kada se dodje do kraja 
       datoteke svaki sledeci poziv funkcije fgetc vraca EOF. */
  }

  /* Zatvaranje otvorenih datoteka. */
  fclose(izlaz);
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}