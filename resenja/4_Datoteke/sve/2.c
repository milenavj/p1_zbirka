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

  /* Iz ulazne datoteke se citaju karakteri i svaki treci karakter
     se upisuje u izlaznu datoteku. */
  while ((c = fgetc(ulaz)) != EOF){
    /* Procitani karakter se upisuje u izlaznu datoteku. */
    fputc(c, izlaz);

    /* Naredna dva karaktera se preskacu. */
    fgetc(ulaz);
    fgetc(ulaz);
    
    /* Ovakvo resenje ce raditi i u slucaju kada broj karaktera u
       datoteci nije deljiv sa 3, jer kada se dodje do kraja 
       datoteke, svaki sledeci poziv funkcije fgetc vraca EOF. */
  }

  /* Zatvaranje otvorenih datoteka. */
  fclose(izlaz);
  fclose(ulaz);

  return 0;
}