#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define MAX_NAZIV 21

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  char ime1[MAX_NAZIV], ime2[MAX_NAZIV];
  char c, karakter;

  /* Ucitavanje imena datoteka i opcije. */
  printf("Unesite imena datoteka i opciju:");
  scanf("%s%s %c", ime1, ime2, &c);

  /* Provera ispravnosti opcije. */
  if (c != 'u' && c != 'l')
    greska("Greska: neispravan unos.\n");

  /* Prva datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */
  ulaz = fopen(ime1, "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje prve datoteke.\n");

  /* Druga datoteka se otvara za pisanje i proverava se da li je
     otvaranje proslo uspesno. */
  izlaz = fopen(ime2, "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje druge datoteke.\n");

  /* Ako je uneta opcija 'u', svi karakteri se pretvaraju u velika
     slova, a ako je opcija 'l' u mala. Izmenjena slova se upisuju
     u izlaznu datoteku. */
  if (c == 'u') 
  {
    while ((karakter = fgetc(ulaz)) != EOF)
      fputc(toupper(karakter), izlaz);
  } 
  else 
  {
    while ((karakter = fgetc(ulaz)) != EOF)
      fputc(tolower(karakter), izlaz);
  }
  
  /* Zatvaraju se datoteke. */  
  fclose(ulaz);
  fclose(izlaz);
  
  return 0;
}
