#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAKS_IME 31
#define MAKS_AUTOMOBILA 100

typedef struct 
{
  char marka[MAKS_IME];
  char model[MAKS_IME];
  float cena;
} Automobil;

/* 
   Struktura Info sadrzi naziv marke automobila, prosek cena za tu
   marku i broj automobila te marke */
typedef struct {
  char marka[MAKS_IME];
  float prosecna_cena;
  int n;
} Info;

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija ucitava informacije o automobilima iz fajla i smesta ih
   u niz struktura. Kao povratnu vrednost vraca broj ucitanih
   automobila. */
int ucitaj(FILE * f, Automobil a[])
{
  int i, n;

  fscanf(f, "%d", &n);
  if (n <= 0 || n > MAKS_AUTOMOBILA) 
    greska("Greska: neispravan broj automobila.\n");
  
  for (i = 0; i < n; i++)
    fscanf(f, "%s %s %f", a[i].marka, a[i].model, &a[i].cena);
  
  return n;
}

/* Funkcija proverava da li se u nizu sa informacijama o markama
   nalazi prosledjena marka. Ukoliko se nalazi, vraca odgovarajucu
   poziciju, a u suprotnom vraca -1. */
int sadrzi(Info info[], int n, char marka[])
{
  int i;
  for (i = 0; i < n; i++)
    if (strcmp(info[i].marka, marka) == 0)
      return i;

  return -1;
}

/* Funkcija popunjava niz sa informacijama o markama na osnovu
   podataka datih u nizu automobila. */
void izracunaj_proseke(Automobil a[], int an, Info info[], int *n)
{
  int i, pozicija, j = 0;
  for(i=0; i < an; i++)
  {
    pozicija = sadrzi(info, j, a[i].marka);
    if(pozicija == -1)
    {
      strcpy(info[j].marka, a[i].marka);
      info[j].prosecna_cena = a[i].cena;
      info[j].n = 1;
      j++;
    }
    else
    {
      info[pozicija].prosecna_cena += a[i].cena;
      info[pozicija].n += 1;
    }
  }
  
  for(i=0; i<j; i++)
    info[i].prosecna_cena /= info[i].n;
  
  *n = j;
}

/* Funkcija ispisuje informacije o prosecnim cenama za svaku
   marku. */
void ispisi_informacije(Info info[], int n)
{
  int i;
  printf("Informacije o prosecnoj ceni po markama:\n");
  for (i = 0; i < n; i++)
    printf("%s %.2f\n", info[i].marka, info[i].prosecna_cena);
}

/* Funkcija ispisuje podatke o automobilima cija je cena manja ili
   jednaka budzetu kojim korisnik raspolaze. */
void ispisi_kandidate(Automobil a[], int an, float budzet, Info info[],
                       int n)
{
  int i, pozicija;
  printf("Kola u vasem cenovnom rangu:\n");
  for (i = 0; i < an; i++)
  {
    if (a[i].cena < budzet)
    {
      pozicija = sadrzi(info, n, a[i].marka);
      printf("%s %s %.2f\n", a[i].marka, a[i].model, 
                             info[pozicija].prosecna_cena);
    }
  }
}

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  Automobil automobili[MAKS_AUTOMOBILA];
  FILE *ulaz;
  char ime_datoteke[MAKS_IME];
  float granica;
  Info info[MAKS_AUTOMOBILA];
  int n, info_n;

  /* Proverava se broj argumenata komandne linije. */
  if (argc != 2)
    greska("Greska: neispravan poziv.\n");

  /* Ucitava se budzet. */
  granica = atof(argv[1]);

  /* Ucitava se naziv datoteke. */
  printf("Unesite naziv datoteke: ");
  scanf("%s", ime_datoteke);

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */  
  ulaz = fopen(ime_datoteke, "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");

  /* Ucitavaju se podaci o automobilima. */
  n = ucitaj(ulaz, automobili);

  /* Izracunavaju se proseci za svaku marku. */
  izracunaj_proseke(automobili, n, info, &info_n);

  /* Ispisuju se podaci za sve marke automobila. */
  ispisi_informacije(info, info_n);

  /* Ispisuju se podaci o automobilima cija je cena manja ili 
     jednaka granici koju je korisnik uneo. */
  ispisi_kandidate(automobili, n, granica, info, info_n);

  /* Zatvara se datoteka. */ 
  fclose(ulaz);
  
  return 0;
}
