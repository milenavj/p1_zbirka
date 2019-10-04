#include <stdio.h>
#include <string.h>
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
  FILE *ulaz;
  char linija[MAKS_LINIJA];
  int k;

  /* Provera broja argumenata komandne linije. */
  if (argc != 3)
    greska("Greska: neispravan poziv.");

  /* Otvaranje datoteke cije se ime zadaje kao prvi argument
     komandne linije i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Racunanje vrednosti drugog argumenta komandne linije. */
  k = atoi(argv[2]);

  /* Funkcija fgets cita jednu liniju iz datoteke. Njeni
     argumenti su: 
     1. Niska u koju ce biti smestena procitana linija
     2. Maksimalna duzina linije 
     3. Datoteka iz koje se cita. 
     Kada dodje do kraja datoteke, kao povratnu vrednost
     funkcija vraca NULL. */
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) {
    /* Ispis svih linija cija je duzina veca od k. */
    if (strlen(linija) > k)
      printf("%s", linija);
  }
  printf("\n");
  
  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}