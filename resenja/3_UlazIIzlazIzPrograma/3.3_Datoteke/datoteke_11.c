#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_REC 101
#define MAKS_IME 21

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija u nisku rezultat smesta nisku rec rotiranu za k mesta u 
   desno. */
void rotiraj(char *rec, int k, char *rezultat) {
  int i, n;

  /* Racunanje duzine reci. */
  n = strlen(rec);

  /* Ako je duzina reci npr. 5, a k ima vrednost 13, onda je
     zapravo potrebno izvrsiti rotaciju za 3 mesta (nema potrebe da 
     se vrte dva cela kruga pre toga). */
  k = k % n;

  /* Karakteri koji se u pocetnoj reci nalaze na pozicijama od 0 do
     k-1, u rezultujucoj reci treba da budu na pozicijama od n-k do 
     n-1. */
  for (i = 0; i < k; i++)
    rezultat[n - k + i] = rec[i];

  /* Slicno, karakteri koji se u pocetnoj reci nalaze na pozicijama
     od k do n-1, u rezultujucoj reci treba da budu na pozicijama od 
     0 do n-k-1. */
  for (i = k; i < n; i++)
    rezultat[i - k] = rec[i];

  /* Na kraj rezultujuce niske se upisuje terminirajuca nula. */
  rezultat[n] = '\0';
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char ime_datoteke[MAKS_IME];
  char rec[MAKS_REC], rezultat[MAKS_REC];
  int k;

  /* Ucitavanje imena ulazne datoteke. */
  printf("Unesite ime datoteke: ");
  scanf("%s", ime_datoteke);

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(ime_datoteke, "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Otvaranje datoteke rotirano.txt za citanje i provera uspeha. */
  izlaz = fopen("rotirano.txt", "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Ucitavanje broja k. */
  printf("Unesite broj k: ");
  scanf("%d", &k);
  if (k < 0)
    greska("Greska: neispravan unos broja k.");

  /* Citanje reci iz ulazne datoteke sve do kraja datoteke. */
  while (fscanf(ulaz, "%s", rec) != EOF) {
    /* Rotiranje procitane reci i upisivanje u izlaznu datoteku. */
    rotiraj(rec, k, rezultat);
    fprintf(izlaz, "%s ", rezultat);
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  exit(EXIT_SUCCESS);
}
