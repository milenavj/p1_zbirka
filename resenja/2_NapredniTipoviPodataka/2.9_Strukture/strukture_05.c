#include <stdio.h>
#include <string.h>

#define MAKS_REC 21
#define MAKS_BROJ_RECI 100

/* Struktura koja opisuje par reci. */
typedef struct {
  char sr[MAKS_REC];
  char en[MAKS_REC];
} ParReci;

/* Funkcija ucitava parove reci u recnik. */
int ucitaj(ParReci recnik[]) {
  int i = 0;
  char sr[MAKS_REC], en[MAKS_REC];

  /* Ucitavanje parovi reci sa standardnog ulaza sve do kraja
     ulaza. */
  printf("Unesite reci i njihove prevode:\n");
  while (scanf("%s %s", sr, en) != EOF) {
    if (i == MAKS_BROJ_RECI)
      break;

    strcpy(recnik[i].sr, sr);
    strcpy(recnik[i].en, en);

    i++;
  }

  return i;
}

/* 
   Funkcija u recniku koji sadrzi n reci trazi prevod reci rec i
   upisuje ga u prevod. Ukoliko se rec ne nalazi u recniku, prevod
   se sastoji od zvezdica pri cemu broj zvezdica odgovara duzini
   nepoznate reci. */
void pronadji_prevod(ParReci recnik[], int n, char rec[],
                     char prevod[]) {
  int i;

  /* Pretraga reci. */
  for (i = 0; i < n; i++) {
    if (strcmp(recnik[i].sr, rec) == 0) {
      strcpy(prevod, recnik[i].en);
      return;
    }
  }

  /* Ukoliko rec nije pronadjena, formira se prevod reci koji se
     sastoji od zvezdica. */
  for (i = 0; rec[i]; i++)
    prevod[i] = '*';
  prevod[i] = '\0';
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  ParReci recnik[MAKS_BROJ_RECI];
  int n;
  char rec[MAKS_REC], prevod[MAKS_REC];
  char c;

  /* Ucitavanje parova reci u recnik. */
  n = ucitaj(recnik);

  /* Ucitavanje recenice i ispis njenog prevoda. */
  printf("Unesite recenicu za prevod: \n");
  do {
    /* Ucitava se rec po rec date recenice i pronalazi se njen
       prevod. */
    scanf("%s", rec);
    pronadji_prevod(recnik, n, rec, prevod);
    printf("%s ", prevod);

    /* Ukoliko je karakter iza reci znak za novi red, onda se
       prekida sa unosom, a ako nije ucitava se sledeca rec. */
    c = getchar();
  } while (c != '\n');

  putchar('\n');

  return 0;
}
