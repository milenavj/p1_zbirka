#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_REC 51
#define MAKS_IME 21

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char ime[MAKS_IME];
  char rec[MAKS_REC], prva_rec[MAKS_REC];
  FILE *ulaz, *izlaz;

  /* Ucitavanje imena ulazne datoteke. */
  printf("Unesite ime datoteke: ");
  scanf("%s", ime);

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(ime, "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Otvaranje datoteke rez.txt za pisanje i provera uspeha. */
  izlaz = fopen("rez.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Iz datoteke se cita prva rec i ispisuje se na standardni
     izlaz. */
  fscanf(ulaz, "%s", prva_rec);
  printf("%s", prva_rec);

  /* Iz datoteke se cita rec po rec sve dok se ne dodje do kraja
     ulaza. */
  while (fscanf(ulaz, "%s", rec) != EOF) {
    /* Procitana rec se ispisuje na standatdni izlaz. */
    printf("%s", rec);

    /* Ukoliko procitana rec sadrzi i prvu rec i karakter '_', onda 
       se ispisuje i u izlaznu datoteku. */
    if (strstr(rec, prva_rec) != NULL && strchr(rec, '_') != NULL)
      fprintf(izlaz, "%s\n", rec);
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
