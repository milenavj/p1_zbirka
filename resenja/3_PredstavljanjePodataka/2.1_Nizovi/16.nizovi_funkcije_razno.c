#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja ucitava dimenziju i elemente niza.
   Kao povratnu vrednost vraca ucitanu dimenziju. */
int ucitaj(int a[])
{
  int i, n;
  
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
  printf("Unesite podatke: ");
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
  
  return n;
}

/* Funkcija koja proverava da li niz sadrzi zadatu vrednost m. */
int sadrzi(int a[], int n, int m)
{
  int i;
  /* Prolazi se kroz sve elemente niza i ukoliko se naidje na 
     element cija je vrednost jednaka m, kao povratna vrednost
     funkcije se vraca 1. */
  for (i = 0; i < n; i++) {
    if (a[i] == m)
      return 1;
  }

  /* Ako se stigne do kraja niza i ne naidje na vrednost koja je
     jednaka broju m, to znaci da se broj ne nalazi u nizu i da
     funkcija treba da vrati 0. */
  return 0;
}

/* Funkcija koja vraca indeks prvog pojavljivanja elementa m
   u nizu a ili -1 ukoliko se m ne nalazi u nizu a. */
int prvo_pojavljivanje(int a[], int n, int m)
{
  int i;
  for (i = 0; i < n; i++)
    if (a[i] == m)
      return i;
    
  /* Ako se stigne do kraja niza i ne naidje na vrednost koja je
     jednaka broju m, to znaci da se broj ne nalazi u nizu i da
     funkcija treba da vrati -1. */
  return -1;
}

/* Funkcija koja vraca indeks poslednjeg pojavljivanja elementa m
   u nizu a ili -1 ukoliko se m ne nalazi u nizu a. */
int poslednje_pojavljivanje(int a[], int n, int m)
{
  int i;

  /* Polazi se od kraja niza i poredi se element po element sa
     zadatim brojem m. */
  for (i = n - 1; i >= 0; i--)
    if (a[i] == m)
      return i;

  /* Ako se stigne do pocetka niza i ne naidje na vrednost koja je
     jednaka broju m, to znaci da se broj ne nalazi u nizu i da
     funkcija treba da vrati -1. */
  return -1;
}

int main()
{
  /* Deklaracije potrebnih promenljivih. */
  int a[MAKS];
  int n, m, i;

  /* Ucitavaju se dimenzija i elementi niza. */
  n = ucitaj(a);

  /* Ucitava se vrednost za pretragu. */
  printf("Unesite vrednost m:");
  scanf("%d", &m);

  /* Ispisuju se rezultati pretrage. */
  if (sadrzi(a, n, m))
  {
    printf("Nadmorska visina %d se nalazi medju podacima.\n", m);
    
    i = prvo_pojavljivanje(a, n, m);
    printf("Pozicija prvog pojavljivanja: %d\n", i);

    i = poslednje_pojavljivanje(a, n, m);
    printf("Pozicija poslednjeg pojavljivanja: %d\n", i);
  }
  else
    printf("Nadmorska visina %d se ne nalazi medju podacima.\n", m);

  exit(EXIT_SUCCESS);
}
