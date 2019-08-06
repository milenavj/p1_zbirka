#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAKS_ELEMENATA 1000

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija ucitava karaktere iz datoteke i smesta ih u niz s. */
int ucitaj_karaktere(char s[], FILE *f) {
  char c;
  int n = 0;
  
  /* Citanje karaktera do kraja datoteke ili dok se ne dodje do
     karaktera koji nije ni slovo ni cifra. */
  while((c = fgetc(f)) != EOF) {
    if(isalpha(c) || isdigit(c))
      s[n] = c;
    else
      break;
    
    n++;
  }
  
  return n;
}

/* Funkcija racuna koliko slova i koliko cifara se nalazi u nizu
   s.*/
void prebroj(char s[], int n, int *broj_slova, int *broj_cifara) {
  int i;
  
  /* Inicijalizacija brojaca. */
  *broj_slova = *broj_cifara = 0;
  
  /* Prebrojavanje slova i cifara. */
  for(i=0; i<n; i++)
    if(isalpha(s[i]))
      (*broj_slova)++;
    else
      (*broj_cifara)++;
}

int main(int argc, char* argv[]) {
  /* Deklaracije potrebnih promenljivih. */
  FILE* ulaz;
  char karakteri[MAKS_ELEMENATA];
  int broj_elemenata, broj_slova, broj_cifara;

  /* Provera broja argumenata komandne linije. */
  if (argc != 2)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje datoteke.");
  
  /* Ucitavanje karaktera datoteke. */
  broj_elemenata = ucitaj_karaktere(karakteri, ulaz);
  
  /* Racunanje i ispis rezultata. */
  prebroj(karakteri, broj_elemenata, &broj_slova, &broj_cifara);
  printf("Broj slova: %d\n", broj_slova);
  printf("Broj cifara: %d\n", broj_cifara);
  
  /* Zatvaranje datoteke. */
  fclose(ulaz);
  
  return 0;
}