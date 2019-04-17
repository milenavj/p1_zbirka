#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAKS_RAZLOMAKA 100

typedef struct
{
  int br;
  int im;
} Razlomak;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija ucitava razlomke u niz razlomaka i kao povratnu
   vrednost vraca broj ucitanih razlomaka. */
int ucitaj_razlomke(Razlomak niz[], FILE * f)
{
  int i, n;
  fscanf(f, "%d", &n);
  
  for (i = 0; i < n; i++) 
  {
    fscanf(f, "%d %d", &niz[i].br, &niz[i].im);
    if (niz[i].im == 0)
      greska("Greska: Imenilac ne moze biti 0.\n");
  }
  return n;
}

/* Funkcija racuna razlomak reciprocan razlomku r. */
Razlomak reciprocni(const Razlomak* r)
{
  if(r->br == 0)
    greska("Greska: nije moguce izracunati reciprocni razlomak.\n");
  
  Razlomak r2;
  r2.im = r->br;
  r2.br = r->im;
  return r2;
}

/* Funkcija racuna brojevnu vrednost razlomka r. */
float vrednost(const Razlomak* r)
{
  return 1.0 * r->br / r->im;
}

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  FILE *ulaz, *izlaz;
  int i, n, opcija_x = 0, opcija_y = 0;
  Razlomak razlomci[MAKS_RAZLOMAKA];
  Razlomak r;

  /* Proverava se broj argumenata. */
  if (argc != 4)
    greska("Greska: neispravan poziv.\n");

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

  /* Ucitava se zadata opcija i postavlja se vrednost odgovarajuceg
     indikatora. */  
  if(strcmp(argv[3], "-x") == 0)
    opcija_x = 1;
  else if(strcmp(argv[3], "-y") == 0)
    opcija_y = 1;
  else if(strcmp(argv[3], "-xy") == 0 || strcmp(argv[3], "-yx") == 0)
    opcija_x = opcija_y = 1;
  else
    greska("Greska: neispravna opcija.\n");

  /* Ucitavaju se podaci o razlomcima. */
  n = ucitaj_razlomke(razlomci, ulaz);

  /* Prolazi se kroz niz razlomaka. */
  for (i = 0; i < n; i++) 
  {
    /* Racuna se reciprocni razlomak. */
    r = reciprocni(&razlomci[i]);

    /* U zavisnosti od unetih opcija, vrsi se odgovarajuci ispis. */
    if (opcija_x)
      fprintf(izlaz, "%d/%d ", r.br, r.im);
    if (opcija_y)
      fprintf(izlaz, "%f ", vrednost(&r));
    fprintf(izlaz, "\n");
  }

  /* Zatvaraju se datoteke. */  
  fclose(ulaz);
  fclose(izlaz);

  return 0;
}
