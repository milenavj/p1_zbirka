#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAKS_DUZINA 31

/* Funkcija ispisuje odgovarajucu poruku na standardni izlaz za
   greske i prekida izvrsavanje programa. */
void greska() {
  fprintf(stderr, "-1\n");
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  /* Deklaracija potrebnih promenljivih. */
  FILE *ulaz;
  int n, i;
  char karakter;
  char opcija;
  char zanr[MAKS_DUZINA], tmp_pesma[MAKS_DUZINA],
      tmp_zanr[MAKS_DUZINA];

  /* Proverava broja argumenata komandne linije. */
  if (argc != 2) {
    greska();
  }

  /* Proverava da li je opcija ispravno zadata tj. da li pocinje
     karakterom -. */
  if (argv[1][0] != '-') {
    greska();
  }

  /* Ako je opcija ispravno zadata, cuva se u promenljivoj opcija. */
  opcija = argv[1][1];

  /* Otvaranje datoteke za citanje i proverava uspesnosti
     otvaranja. */
  ulaz = fopen("pesme.txt", "r");
  if (ulaz == NULL) {
    greska();
  }

  /* Ucitavanje broja pesama. */
  fscanf(ulaz, "%d", &n);

  /* Analiza zadate opcije. */
  switch (opcija) {

  case 'p':
    /* 1) cita se karakter za pretragu */
    scanf("%c", &karakter);

    /* 2) za svaku pesmu */
    for (i = 0; i < n; i++) {
      /* 3) citaju se ime pesme i zanr pesme */
      fscanf(ulaz, "%s", tmp_pesma);
      fscanf(ulaz, "%s", tmp_zanr);

      /* 4) proverava se da li ime pesme pocinje procitanim
         karakterom */
      if (toupper(tmp_pesma[0]) == toupper(karakter)) {
        /* 5) ispisuje se ime pesme */
        printf("%s\n", tmp_pesma);
      }
    }
    break;

  case 'z':
    /* 1) ucitava se zanr */
    scanf("%s", zanr);

    /* 2) za svaku pesmu */
    for (i = 0; i < n; i++) {
      /* 3) citaju se ime pesme i zanr pesme */
      fscanf(ulaz, "%s", tmp_pesma);
      fscanf(ulaz, "%s", tmp_zanr);

      /* 4) proverava se da li zanr pesme odgovara procitanom zanru 
       */
      if (strcmp(tmp_zanr, zanr) == 0) {
        /* 5) ispisuje se ime pesme */
        printf("%s\n", tmp_pesma);
      }
    }
    break;

  default:
    /* Ako je zadata pogresna opcija, prekida se izvrsavanje
       programa. */
    greska();
  }

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
