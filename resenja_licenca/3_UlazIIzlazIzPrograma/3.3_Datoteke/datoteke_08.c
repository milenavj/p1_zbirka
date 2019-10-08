/*****************************************************************
* Ovo delo zaštićeno je licencom Creative Commons CC BY-NC-ND 4.0
* (Attribution-NonCommercial-NoDerivatives 4.0 International License).
* Za detalje pogledati LICENSE.TXT
* Autori: Milena Vujosevic Janicic, Jovana Kovacevic,  
*         Danijela Simic, Andjelka Zecevic, Aleksandra Kocic
******************************************************************/

#include <stdio.h>
#include <stdlib.h>

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz;
  char c;
  int broj_zagrada = 0, nisu_uparene = 0;

  /* Provera broja argumenata komandne linije. */
  if (argc != 2)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje datoteke.");

  /* Cita se karakter po karakter i proverava se da li je procitana
     zagrada. Ako se naidje na otvorenu zagradu, brojac se uvecava.
     Ako se naidje na zatvorenu zagradu, brojac se smanjuje. Zagrade 
     su ispravno uparene ukoliko je ovaj brojac na kraju 0. Dodatno, 
     ukoliko brojac u bilo kom trenutku postane negativan, to znaci
     da je zatvorena zagrada procitana pre otvorene, tako da ni u
     tom slucaju zagrade nisu uparene. */
  while ((c = fgetc(ulaz)) != EOF) {
    if (c == '(')
      broj_zagrada++;
    else if (c == ')')
      broj_zagrada--;

    if (broj_zagrada < 0) {
      nisu_uparene = 1;
      break;
    }
  }

  /* Ispis rezultata. */
  if (broj_zagrada != 0 || nisu_uparene)
    printf("Zagrade nisu uparene.\n");
  else
    printf("Zagrade jesu uparene.\n");

  /* Zatvaranje datoteke. */
  fclose(ulaz);

  exit(EXIT_SUCCESS);
}
