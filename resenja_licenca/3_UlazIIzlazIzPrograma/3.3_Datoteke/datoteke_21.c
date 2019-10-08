/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAKS_STUDENATA 100

/* Struktura koja opisuje studenta. */
typedef struct {
  char korisnicko_ime[8];
  float prosek;
} Student;

int main() {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  Student studenti[MAKS_STUDENATA];
  int ocena1, ocena2, ocena3, ocena4, ocena5, zbir_ocena;
  int i = 0, n;
  float maksimalni_prosek = 0;

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */     
  ulaz = fopen("studenti.txt", "r");
  if (ulaz == NULL) {
    fprintf(stderr, "Greska: neuspesno otvaranje "
            "ulazne datoteke.\n");
    exit(EXIT_FAILURE);
  }

  /* Citanje podataka o studentima sve dok se ne dodje do kraja
     datoteke. */
  while (fscanf(ulaz, "%s%d%d%d%d%d", studenti[i].korisnicko_ime,
          &ocena1, &ocena2, &ocena3, &ocena4, &ocena5) != EOF) {
    /* Racunanje proseka trenutnog studenta. */
    zbir_ocena = ocena1 + ocena2 + ocena3 + ocena4 + ocena5;
    studenti[i].prosek = zbir_ocena / 5.0;

    /* Azuriranje maksimalnog proseka. */
    if (studenti[i].prosek > maksimalni_prosek)
      maksimalni_prosek = studenti[i].prosek;

    /* Prelazak na sledeceg studenta. */
    i++;
  }

  /* Promenljiva n cuva ukupan broj studenata. */
  n = i;

  /* Ispis svih studenata sa maksimalnim prosekom. */
  printf("Studenti sa najvecim prosekom:\n");
  for (i = 0; i < n; i++)
    if (studenti[i].prosek == maksimalni_prosek)
      printf("Korisnicko ime: %s\nProsek ocena: %.2f\n\n",
             studenti[i].korisnicko_ime, studenti[i].prosek);

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}