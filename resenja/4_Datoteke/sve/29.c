#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_LINIJA 81
#define MAKS_REC 31

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija broji koliko puta se niska t javlja u okviru niske s. */
int broj_pojavljivanja(char s[], char t[])
{
  int br = 0, i;
  int tn = strlen(t);
  int sn = strlen(s);

  /* Funkcija strncmp(s,t,n) poredi prvih n karaktera niski s i t.
     U petlji se vrsi poredjenje niske t sa svim podniskama niske
     s cija je duzina tn.
     Na primer, ako je s=abcab, a t=ab, tada je sn=5, a tn=2.
     za i=0, zove se strncmp("abcab", "ab", 2) i na taj nacin se 
             porede "ab" i "ab".
     za i=1, zove se strncmp("bcab", "ab", 2) i na taj nacin se
             porede "bc" i "ab". 
     ...
     za i=sn-st=5-2=3, zove se strncmp("ab", "ab", 2) i na taj
             se porede "ab" i "ab". */
  for (i = 0; i <= sn-tn; i++) 
    if(strncmp(s + i, t, tn) == 0)
      br++;

  return br;
}

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  char rec[MAKS_REC];
  char linija[MAKS_LINIJA];
  FILE *ulaz, *izlaz;
  int n, br;

  /* Proverava se broj argumenata komandne linije. */
  if (argc != 3)
    greska("Greska: neispravan poziv.");

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */  
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");

  /* Izlazna datoteka se otvara za pisanje i proverava se da li je
     otvaranje proslo uspesno. */  
  izlaz = fopen(argv[2], "w");
  if (izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.\n");

  /* Ucitava se broj n i vrsi se provera ispravnosti. */  
  printf("Unesite broj n: ");
  scanf("%d", &n);
  if (n <= 0)
    greska("Greska: neispravan unos.\n");

  /* Ucitava se trazena rec. */
  fscanf(ulaz, "%s", rec);
  
  /* Iz ulazne datoteke se cita linija po linija i u izlaznu
     datoteku se upisuju sve linije koje trazenu rec sadrze bar
     n puta. */
  while (fgets(linija, MAKS_LINIJA, ulaz) != NULL) 
  {
    br = broj_pojavljivanja(linija, rec);
    if (br >= n)
      fprintf(izlaz, "%d: %s\n", br, linija);
  }
  
  /* Zatvaraju se datoteke. */  
  fclose(ulaz);
  fclose(izlaz);
  
  return 0;
}
