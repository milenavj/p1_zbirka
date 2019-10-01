#include <stdio.h>
#include <stdlib.h>

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  float broj, najveci_broj;

  /* Otvaranje datoteke brojevi.txt za citanje i provera uspeha. */
  ulaz = fopen("brojevi.txt", "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Promenljiva u koju se smesta najveci broj se inicijalizuje na
     prvi broj iz datoteke. Ukoliko se pri prvom citanju dodje do
     kraja datoteke, ispisuje se odgovarajuca poruka. */
  if (fscanf(ulaz, "%f", &najveci_broj) == EOF)
    greska("Greska: datoteka je prazna.");

  /* Iz datoteke se cita broj po broj, sve dok se ne dodje do kraja
     datoteke i trazi se najveci procitani broj. */
  while (fscanf(ulaz, "%f", &broj) != EOF)
    if (broj > najveci_broj)
      najveci_broj = broj;

  /* Ispis rezultata. */
  printf("Najveci broj je: %g\n", najveci_broj);

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  return 0;
}