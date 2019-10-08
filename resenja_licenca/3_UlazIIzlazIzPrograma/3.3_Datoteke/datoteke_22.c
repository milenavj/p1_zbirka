/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_PUNO_IME 101
#define MAKS_OCENA 10

/* Struktura koja opisuje studenta. */
typedef struct {
  char puno_ime[MAKS_PUNO_IME];
  int ocene[MAKS_OCENA];
  int broj_ocena;
  float prosek;
} Student;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  char ime[MAKS_PUNO_IME], prezime[MAKS_PUNO_IME];
  int i = 0, j, ocena, suma_ocena;
  Student student, maks_student;
  float maks_prosek;

  /* Provera broja argumenata komandne linije. */
  if (argc != 2)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Iz datoteke se ucitavaju podaci o studentima sve dok se ne
     dodje do kraja datoteke. */
  while (fscanf(ulaz, "%s%s", ime, prezime) != EOF) {
    /* Od imena i prezimena se formira puno ime. */
    strcpy(student.puno_ime, ime);
    strcat(student.puno_ime, " ");
    strcat(student.puno_ime, prezime);

    /* Ucitavanje ocena sve dok se ne ucita broj 0. */
    j = 0;
    suma_ocena = 0;
    while (1) {
      fscanf(ulaz, "%d", &ocena);
      if (ocena == 0)
        break;

      student.ocene[j] = ocena;
      suma_ocena += ocena;
      j++;
    }

    /* Racunanje proseka ocena. */
    student.broj_ocena = j;
    student.prosek = (float) suma_ocena / j;

    /* Ukoliko je u pitanju student ciji je prosek veci od trenutno
       najveceg proseka, pamte se njegovi podaci i azurira se
       vrednost najveceg proseka. */
    if (student.prosek > maks_prosek) {
      maks_prosek = student.prosek;
      maks_student = student;
    }
  }

  /* Ispis podataka o studentu sa najvecim prosekom. */
  printf("%s ", maks_student.puno_ime);
  for (i = 0; i < maks_student.broj_ocena; i++)
    printf("%d ", maks_student.ocene[i]);
  printf("%.2f\n", maks_student.prosek);

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
