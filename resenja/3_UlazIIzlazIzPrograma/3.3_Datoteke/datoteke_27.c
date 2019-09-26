#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_LINIJA 81
#define MAKS_REC 31

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i prekida izvrsavanje programa. */
void greska(char *poruka) {
  fprintf(stderr, "%s\n", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija broji koliko puta se niska t javlja u okviru niske s. */
int broj_pojavljivanja(char s[], char t[]) {
  int brojac = 0, i;
  int tn = strlen(t);
  int sn = strlen(s);

  /* Funkcija strncmp(s,t,n) poredi prvih n karaktera niski s i t.
     U petlji se vrsi poredjenje niske t sa svim podniskama niske s 
     cija je duzina tn. 
     Na primer, ako je s = "abcab", a t = "ab", tada je sn = 5, 
     a tn = 2. 
     Za i = 0, zove se strncmp("abcab", "ab", 2) i na taj nacin se
               porede "ab" i "ab". 
     Za i = 1, zove se strncmp("bcab", "ab", 2) i na taj nacin se
               porede "bc" i "ab". 
     ... 
     Za i = sn - st = 5 - 2 = 3, zove se strncmp("ab", "ab", 2) i 
               na taj nacin se porede "ab" i "ab". */
  for (i = 0; i <= sn - tn; i++)
    if (strncmp(s + i, t, tn) == 0)
      brojac++;

  return brojac;
}

int main(int argc, char *argv[]) {
  /* Deklaracije potrebnih promenljivih. */
  char rec[MAKS_REC];
  char linija[MAKS_LINIJA];
  FILE *ulaz, *izlaz;
  int n, brojac;

  /* Provera broja argumenata komandne linije. */
  if (argc != 3)
    greska("Greska: neispravan poziv.");

  /* Otvaranje ulazne datoteke za citanje i provera uspeha. */
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.");

  /* Otvaranje izlazne datoteke za pisanje i provera uspeha. */
  izlaz = fopen(argv[2], "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.");

  /* Ucitavanje broja n i provera ispravnosti unosa. */
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n <= 0)
    greska("Greska: neispravan unos.");

  /* Ucitavanje trazene reci. */
  fscanf(ulaz, "%s", rec);

  /* Iz ulazne datoteke se cita linija po linija i u izlaznu
     datoteku se upisuju sve linije koje trazenu rec sadrze bar n
     puta. */
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) {
    brojac = broj_pojavljivanja(linija, rec);
    if (brojac >= n)
      fprintf(izlaz, "%d: %s\n", brojac, linija);
  }

  /* Zatvaranje datoteka. */
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
