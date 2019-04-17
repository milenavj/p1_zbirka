#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Funkcija ispisuje prosledjenu poruku o gresci na standardni
   izlaz za greske i izlazi iz programa. */
void greska(char* poruka)
{
  fprintf(stderr, "%s", poruka);
  exit(EXIT_FAILURE);
}

/* Funkcija racuna broj cifara broja x. */
int broj_cifara(int x)
{
  int brojac = 0;

  do 
  {
    brojac++;
    x /= 10;
  } while (x);

  return brojac;
}

/* Funkcija broji koliko ima k-tocifrenih brojeva u datoteci f. */
int prebrojavanje(FILE * f, int k)
{
  int n, x, i, brojac;

  /* Ucitava se broj brojeva u datoteci. */
  fscanf(f, "%d", &n);
  if (n <= 0)
    greska("Greska: neispravna vrednost broja n.\n");

  /* Cita se broj po broj i za svaki procitani broj se racuna
     broj cifara. Ukoliko je on jednak k, uvecava se odgovarajuci
     brojac. */
  brojac = 0;
  for (i = 0; i < n; i++) 
  {
    fscanf(f, "%d", &x);
    if (broj_cifara(x) == k)
      brojac++;
  }

  /* Povratna vrednost funkcije je broj k-tocifrenih brojeva. */
  return brojac;
}

int main(int argc, char *argv[])
{
  /* Deklaracije potrebnih promenljivih. */
  int k;
  FILE *ulaz;

  /* Proverava se broj argumenata komandne linije. */
  if (argc != 3) 
    greska("Greska: neispravan poziv.\n");

  /* Ulazna datoteka se otvara za citanje i proverava se da li je
     otvaranje proslo uspesno. */ 
  ulaz = fopen(argv[1], "r");
  if (ulaz == NULL)
    greska("Greska: neuspesno otvaranje ulazne datoteke.\n");

  /* Cita se broj k i vrsi se provera ispravnosti. */
  k = atoi(argv[2]);
  if (k <= 0)
    greska("Greska: neispravna vrednost broja k.\n");

  /* Ispis rezultata. */
  printf("Broj %d-cifrenih brojeva: %d\n", k, 
         prebrojavanje(ulaz, k));

  /* Zatvara se datoteka. */ 
  fclose(ulaz);
  
  return 0;
}
