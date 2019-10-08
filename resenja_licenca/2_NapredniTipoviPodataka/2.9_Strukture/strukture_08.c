/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS_IME 21
#define BROJ_OCENA 9
#define MAKS_DJAKA 30

/* Struktura koja opisuje djaka. */
typedef struct {
  char ime[MAKS_IME];
  int ocena[BROJ_OCENA];
} Djak;

/* Funkcija proverava ispravnost date ocene. */
void provera_ocene(int ocena) {
  if (ocena < 1 || ocena > 5) {
    printf("Greska: neispravna ocena.\n");
    exit(EXIT_FAILURE);
  }
}

/* Funkcija ucitava podatke o djacima u niz. */
int ucitaj(Djak niz[]) {
  int i = 0, j;

  while (i < MAKS_DJAKA) {
    printf("Unesite podatke o djaku: ");
    /* Ucitavanje imena. */
    if (scanf("%s", niz[i].ime) == EOF)
      break;

    /* Ucitavanje ocena. */
    for (j = 0; j < BROJ_OCENA; j++) {
      scanf("%d", &niz[i].ocena[j]);
      provera_ocene(niz[i].ocena[j]);
    }
    i++;
  }

  return i;
}

/* Funkcija racuna prosecnu ocenu datog djaka. */
float prosecna_ocena(const Djak *djak) {
  int j;
  float suma = 0;
  for (j = 0; j < BROJ_OCENA; j++)
    suma += djak->ocena[j];

  return suma / BROJ_OCENA;
}

int main() {
  /* Deklaracija potrebnih promenljivih. */
  Djak niz[MAKS_DJAKA];
  int i, j, n;
  float prosek;

  /* Ucitavanje podataka o djacima. */
  n = ucitaj(niz);

  /* Ispis imena nedovoljnih djaka. */
  printf("\n\nNEDOVOLJNI: ");
  for (i = 0; i < n; i++)
    for (j = 0; j < BROJ_OCENA; j++)
      if (niz[i].ocena[j] == 1) {
        printf("%s ", niz[i].ime);
        break;
      }
  printf("\n");

  /* Ispis imena odlicnih djaka. */
  printf("ODLICNI: ");
  for (i = 0; i < n; i++) {
    prosek = prosecna_ocena(&niz[i]);
    if (prosek >= 4.5)
      printf("%s ", niz[i].ime);
  }
  printf("\n");

  exit(EXIT_SUCCESS);
}
