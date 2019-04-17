#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_LINIJA 201

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
  /* Deklaracije potrebnih promenljivih. */
  int i = 1;
  char *d1, *d2;
  FILE *dat1, *dat2;
  char linija1[MAKS_LINIJA];
  char linija2[MAKS_LINIJA];
  
  /* Proverava se broj argumenata komandne linije. */
  if (argc != 3)
    greska("Greska: neispravan poziv.\n");

  /* Datoteke ciji su nazivi dati kao argumenti komandne linije
     se otvaraju za citanje. */
  dat1 = fopen(argv[1], "r");
  dat2 = fopen(argv[2], "r");

  /* Proverava se da li su obe datoteke uspesno otvorene. */
  if (dat1 == NULL || dat2 == NULL)
    greska("Greska: neuspesno otvaranje datoteke.\n");

  /* Iz obe datoteke se cita prva linija. */
  d1 = fgets(linija1, MAKS_LINIJA, dat1);
  d2 = fgets(linija2, MAKS_LINIJA, dat2);

  /* Dok god se ne dodje do kraja jedne od datoteka citaju se
     preostale linije. */
  while (d1 != NULL && d2 != NULL) 
  {
    /* Vrsi se poredjenje ucitanih linija. */
    if (strcmp(linija1, linija2) != 0)
      printf("%d ", i);

    /* Prelazi se na sledece linije. */
    d1 = fgets(linija1, MAKS_LINIJA, dat1);
    d2 = fgets(linija2, MAKS_LINIJA, dat2);

    i++;
  }

  /* Iz prethodne petlje je moglo da se izadje u 3 slucaja:
     1. Doslo se do kraja prve datoteke.
     2. Doslo se do kraja druge datoteke.
     3. Doslo se do kraja obe datoteke.
     U slucaju da se desio treci slucaj, nijedna od naredne dve
     petlje se nece izvrsiti.
     U prvom slucaju ce se izvrsiti samo prva petlja, a u 
     drugom slucaju druga.
   */
  
  /* Ispisuju se preostali redni brojevi linija prve datoteke. */
  while (d1 != NULL) 
  {
    printf("%d ", i);
    d1 = fgets(linija1, MAKS_LINIJA, dat1);
    i++;
  }

  /* Ispisuju se preostali redni brojevi linija druge datoteke. */  
  while (d2 != NULL) 
  {
    printf("%d ", i);
    d2 = fgets(linija2, MAKS_LINIJA, dat2);
    i++;
  }

  /* Zatvaraju se datoteke. */  
  fclose(dat1);
  fclose(dat2);

  return 0;
}