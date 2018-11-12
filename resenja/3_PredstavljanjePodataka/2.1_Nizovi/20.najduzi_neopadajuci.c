#include <stdio.h>
#include <stdlib.h>
#include <stdlib.h>

/* Maksimalan broj dana u mesecu je 31, ali dani pocinju od 1, pa
   je potrebno odvojiti 32 mesta u nizu jer se nulti ne koristi. */
#define MAKS_DANA 32

/* Funkcija ucitava dimenziju i elemente niza. */
int ucitaj(int niz[])
{
  int i, n;

  printf("Unesite dimenziju niza: ");
  scanf("%d", &n);
  
  if (n <= 0 || n > MAKS_DANA) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  printf("Unesite broj prodatih artikala: ");
  for (i = 0; i < n; i++)
    scanf("%d", &niz[i]);

  return n;
}

int najduzi_neopadajuci(int a[], int n)
{
  int i;
  /* Na pocetku i duzina trenutne serije i duzina maksimalne serije
     se inicijalizuju na 1. */
  int duzina_trenutne_serije = 1;
  int duzina_najduze_serije = 1;

  for (i = 1; i < n; i++) {
    /* Proverava se da li uzastopni elementi ispunjavaju
       neopadajuci uslov. Ako je to slucaj uvecava se duzina
       serije, a ako nije, duzina trenutne serije se vraca na 1,
       kako bi se ispravno racunala duzina sledece serije. */
    if (a[i] >= a[i - 1])
      duzina_trenutne_serije++;
    else
      duzina_trenutne_serije = 1;
    
    /* Ukoliko je trenutna duzina serije veca od duzine do sada
       najduze serije, parametar za duzinu najduze serije se
       postavlja na novu, vecu vrednost. */
    if (duzina_trenutne_serije > duzina_najduze_serije)
      duzina_najduze_serije = duzina_trenutne_serije;
  }

  return duzina_najduze_serije;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS_DANA], n;

  /* Ucitava se ulaz. */
  n = ucitaj(a);

  /* Ispis rezultata. */
  printf("Duzina najduzeg neopadajuceg prodavanja je %d.\n",
         najduzi_neopadajuci(a, n));

  exit(EXIT_SUCCESS);
}
