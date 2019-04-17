#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAKS_TACAKA 50

typedef struct 
{
  int x,y;
} Tacka;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija racuna rastojanje tacke od koordinatnog pocetka. */
double rastojanje_od_koordinatnog_pocetka(const Tacka* a)
{
  return sqrt(pow(a->x, 2) + pow(a->y, 2));
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  FILE* ulaz, *izlaz;
  int n, i;
  Tacka t, maks_t;
  double r, maks_r = -1;
  
  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */  
  ulaz = fopen("tacke.txt", "r");
  if(ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");

  /* Izlazna datoteka se otvara za pisanje i proverava se da li je
     otvaranje proslo uspesno. */  
  izlaz = fopen("rastojanja.txt", "w");
  if(izlaz == NULL)
    greska("Greska: neuspesno otvaranje izlazne datoteke.\n");
  
  /* Ucitava se broj tacaka i vrsi se provera ispravnosti. */
  fscanf(ulaz, "%d", &n);
  if(n < 0 || n > MAKS_TACAKA)
    greska("Greska: neispravan broj tacaka.\n");
  
  /* Iz datoteke se cita tacka po tacka. */
  for(i=0; i<n; i++)
  {
    fscanf(ulaz, "%d%d", &t.x, &t.y);
    
    /* Racuna se rastojanje tacke t od koordinatnog pocetka. */
    r = rastojanje_od_koordinatnog_pocetka(&t);
    
    /* Rastojanje se ispisuje u datoteku. */
    fprintf(izlaz, "%.2lf\n", r);
    
    /* Ukoliko je vece od trenutno najveceg rastojanja, azuriraju
       se vrednosti maksimanog rastojanje i odgovarajuce tacke. */
    if(r > maks_r)
    {
      maks_r = r;
      maks_t = t;
    }
  }
  
  /* Ispis rezultata. */
  printf("Najudaljenija tacka: (%d, %d)\n", maks_t.x, maks_t.y);
  
  /* Zatvara se datoteka. */ 
  fclose(ulaz);
  
  return 0;
}