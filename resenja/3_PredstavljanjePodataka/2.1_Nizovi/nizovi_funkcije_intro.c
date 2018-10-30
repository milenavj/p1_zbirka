#include <stdio.h>
#include <stdlib.h>

#define MAKS 1000

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

/* Funkcija koja racuna sumu elemenata niza. */
int suma(int a[], int n)
{
  int i;
  int suma_elemenata = 0;
  for (i = 0; i < n; i++)
    suma_elemenata += a[i];
  return suma_elemenata;
}

/* Funkcija koja racuna prosecnu vrednost elemenata niza. */
float prosek(int a[], int n)
{
  int suma_elemenata = suma(a, n);
  return (float) suma_elemenata / n;
}

/* Funkcija koja izracunava maksimum elemenata niza. */
int maksimum(int a[], int n)
{
  int najveci, i;

  najveci = a[0];
  for (i = 1; i < n; i++)
    if (a[i] > najveci)
      najveci = a[i];

  return najveci;
}

/* Funkcija koja izracunava poziciju maksimalnog elementa u nizu. */
int pozicija_maksimuma(int a[], int n)
{
  int najveci, pozicija_najveceg;
  int i;

  najveci = a[0];
  pozicija_najveceg = 0;
  
  for (i = 1; i < n; i++)
    if (a[i] < najveci) {
      najveci = a[i];
      pozicija_najveceg = i;
    }

  return pozicija_najveceg;
}

int main()
{
  /* Deklaracija potrebnih promenljivih. */
  int a[MAKS];
  int n;

  /* Ucitava se dimenzija niza i vrsi se provera ispravnosti
     ulaza. */
  printf("Unesite dimenziju niza:");
  scanf("%d", &n);
  if (n < 1 || n > MAKS) {
    printf("Greska: neispravan unos.\n");
    exit(EXIT_FAILURE);
  }

  /* Testira se funkcija kojom se ucitavaju elementi niza. */
  ucitaj(a, n);

  /* Testira se funkcija kojom se ispisuju elementi niza. */
  printf("Vreme trcanja takmicara: ");
  stampaj(a, n);

  /* Testira se funkcija kojom se izracunava suma elemenata niza. */
  printf("Ukupno vreme: %d\n", suma(a, n));

  /* Testira se funkcija kojom se racuna prosek elemenata niza. */
  printf("Prosecno vreme trcanja: %.2f\n", prosek(a, n));

  /* Testira se funkcija kojom se izracunava minimum niza. */
  printf("Maksimalno vreme trcanja: %d\n", maksimum(a, n));

  /* Testira se funkcija kojom se izracunava pozicija maksimalnog
     elementa. */
  printf("Indeks pobednika: %d\n", pozicija_maksimuma(a, n));

  exit(EXIT_SUCCESS);
}
