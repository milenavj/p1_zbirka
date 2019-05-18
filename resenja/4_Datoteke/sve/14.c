#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_BROJ_RECI 256
#define MAKS_DUZINA_RECI 51
#define MAKS_IME 21

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  char ime_datoteke[MAKS_IME];
  char niz_reci[MAKS_BROJ_RECI][MAKS_DUZINA_RECI];
  FILE *ulaz, *izlaz;
  int n, i, k, indikator;

  /* Ucitavanje imena ulazne datoteke. */
  printf("Unesite ime datoteke: ");
  scanf("%s", ime_datoteke);

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(ime_datoteke, "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Iz datoteke se ucitava broj reci. */
  fscanf(ulaz, "%d", &n);
  if (n < 0 || n > MAKS_BROJ_RECI)
    greska("Greska: neispravna vrednost broja reci.");

  /* Ucitavanje rec po rec iz datoteke, smesta se u niz i ispisuje
     se na standardni izlaz. */
  for (i = 0; i < n; i++) {
    fscanf(ulaz, "%s", niz_reci[i]);
    printf("%s ", niz_reci[i]);
  }

  /* Otvaranje izlazne datoteke za pisanje i provera uspeha. */
  izlaz = fopen("rez.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* U izlaznu datoteku se upisuju reci, izostavljajuci duplikate. */
  for (i = 0; i < n; i++) {
    /* Za rec na poziciji i se proverava da li se ona nalazi negde
       na pozicijama od 0 do i. Ukoliko se nalazi, to znaci da je
       vec upisana u datoteku i da je treba preskociti. U tom
       slucaju vrednost promenljive indikator ce biti postavljena
       na 1. */
    indikator = 0;
    for (k = 0; k < i; k++)
      if (strcmp(niz_reci[k], niz_reci[i]) == 0) {
        indikator = 1;
        break;
      }

    /* Ako indikator ima vrednost 0, to znaci da se doslo do prvog
       pojavljivanja reci i da je treba upisati u izlaznu datoteku. 
     */
    if (!indikator)
      fprintf(izlaz, "%s\n", niz_reci[i]);
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
