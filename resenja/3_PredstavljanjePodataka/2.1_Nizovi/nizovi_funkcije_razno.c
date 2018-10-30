#include <stdio.h>
#include <stdlib.h>

#define MAKS 100

/* Funkcija koja ucitava elemente niza. */
void ucitaj(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
}

/* Funkcija koja ispisuje elemente niza. */
void stampaj(int a[], int n)
{
  int i;
  for (i = 0; i < n; i++)
    printf("%d ", a[i]);
  printf("\n");
}

/* Funkcija koja proverava da li niz sadrzi zadatu vrednost m. */
int sadrzi(int a[], int n, int m)
{
  int i;
  /* Prolazi se kroz sve elemente niza i ukoliko se naidje na element
     cija je vrednost jednaka m, kao povratna vrednost funkcije se
     vraca 1. */
  for (i = 0; i < n; i++) {
    if (a[i] == m)
      return 1;
  }

  /* Ako se stigne do kraja niza i ne naidje na vrednost koja je
     jednaka broju m, to znaci da se broj ne nalazi u nizu i da
     funkcija treba da vrati 0. */
  return 0;
}

/* Funkcija koja vraca vrednost prve pozicije na kojoj se nalazi
   element koji ima vrednost m, ili -1 ukoliko element nije u nizu. 
 */
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

/* Funkcija koja vraca vrednost poslednje pozicije na kojoj se
   nalazi element koji ima vrednost m, ili -1 ukoliko element nije
   u nizu. */
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

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza:");
  scanf("%d", &n);
  if (n < 1 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Ucitavaju se i ispisuju elementi niza. */
  ucitaj(a, n);
  printf("Ucitani niz:");
  stampaj(a, n);

  /* Ucitava se vrednost za pretragu. */
  printf("Unesi jedan ceo broj:");
  scanf("%d", &m);

  /* Testira se rad napisanih funkcija. */
  if (sadrzi(a, n, m))
    printf("Niz sadrzi element cija je vrednost %d\n", m);
  else
    printf("Niz ne sadrzi element cija je vrednost %d\n", m);

  i = prvo_pojavljivanje(a, n, m);
  if (i != -1)
    printf("Indeks njegovog prvog pojavljivanja u "
           "nizu je %d\n", i);


  i = poslednje_pojavljivanje(a, n, m);
  if (i != -1)
    printf("Indeks njegovog poslednjeg pojavljivanja u "
           "nizu je %d\n", i);

  exit(EXIT_SUCCESS);
}
