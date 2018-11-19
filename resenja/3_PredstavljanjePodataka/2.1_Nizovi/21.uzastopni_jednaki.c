#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija ucitava elemente niza dimenzije n. */
void ucitaj(int a[], int n)
{
  int i;  
  printf("Unesite elemente niza: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija vraca duzinu najduze serije jednakih elemenata niza. */
int najduza_serija(int a[], int n)
{
  int i;
  /* Na pocetku i duzina trenutne serije i duzina maksimalne serije
     se inicijalizuju na 1. */
  int trenutna_serija = 1;
  int najduza_serija = 1;

  for (i = 1; i < n; i++) {
    /* Proverava se da li su uzastopni elementi jednaki. Ako je to
       slucaj uvecava se duzina serije. Ako uzastopni elementi nisu
       jednaki serija je prekinuta i paramtar za duzinu serije se
       postavlja ponovo na 1 da bi mogla da se racuna duzina
       sledece serije. */
    if (a[i] == a[i - 1])
      trenutna_serija++;
    else
      trenutna_serija = 1;

    /* Ukoliko je trenutna duzina serije veca od duzine do sada
       najduze serije, parametar za duzinu najduze serije se
       postavlja na novu, vecu vrednost. */
    if (trenutna_serija > najduza_serija)
      najduza_serija = trenutna_serija;
  }

  return najduza_serija;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int n, a[MAKS];

  /* Ucitava se dimenzija niza i vrsi se provera 
     ispravnosti ulaza. */
  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  if (n <= 0 || n > MAKS) 
  {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se elementi niza. */
  ucitaj(a, n);

  /* Ispis rezultata. */
  printf("Duzina najduze serije je %d.\n", najduza_serija(a, n));

  exit(EXIT_SUCCESS);
}
